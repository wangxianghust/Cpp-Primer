#ifndef E27_H
#define E27_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::ifstream;
using std::istringstream;
using std::shared_ptr;
using std::ostream;

using line_no = vector<string>::size_type;
class QueryResult;
class TextQuery{
public:
	TextQuery(ifstream &);
	QueryResult query(const string &) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is): file(new vector<string>){
	string text;
	while(getline(is, text)){
		file->push_back(text);
		int n = file->size() -1;
		istringstream line(text);
		string word;
		while(line >> word){
			auto &lines = wm[word];
			if(!lines){
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

class QueryResult{
	friend std::ostream &print(std::ostream &, const QueryResult &);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f): sought(s), lines(p), file(f) {}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<std::vector<string>> file;
};

QueryResult TextQuery::query(const string &sought) const{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end()){
		return QueryResult(sought, nodata, file);
	} else {
		return QueryResult(sought, loc->second, file);
	}
}

ostream &print(ostream &os, const QueryResult &qr){
	auto size = qr.lines->size();
	os << qr.sought << " occurs " << size << ((size > 1) ? " times" : " time") << endl;
	for(auto num : *(qr.lines)){
		os << " line( " << num+1 << " ) " << *(qr.file->begin() + num) << endl; 
	}
	return os;
}
#endif