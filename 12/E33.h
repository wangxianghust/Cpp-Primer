#ifndef E33_H
#define E33_H

#include "E19_3.h"
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

using std::map;
using std::set;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::begin;
using std::end;

class QueryResult;

class TextQuery{
public:
	// using line_no = StrBlob::size_type;
	using line_no = vector<string>::size_type;
	TextQuery();
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	StrBlob file;
	map<string, shared_ptr<set<line_no>>> wordmap;
};

class QueryResult{
public:
	friend void print(ostream&, QueryResult&);
public:
	// using line_no = StrBlob::size_type;
	using line_no = vector<string>::size_type;
	using ResultIter = set<line_no>::iterator;
	QueryResult(string w, shared_ptr<set<line_no>> l, const StrBlob& f):
				search_word(w), lines(l), file(f) {}
	ResultIter begin() const { return (*lines).begin(); }
	ResultIter end() const { return (*lines).end(); }
	shared_ptr<StrBlob> get_file() const { return make_shared<StrBlob>(file); }
private:
	string search_word;
	shared_ptr<set<line_no>> lines;
	StrBlob file;
};

void print(ostream&, QueryResult&);


///////////////////////////////////////////////////
// These member function should put in the , 
// but has the compiler error I can not solve it.
//////////////////////////////////////////////////
TextQuery::TextQuery(ifstream& infile){
	string text, word;
	line_no lineNum = 0;
	while(getline(infile, text)){
		++ lineNum;
		file.push_back(text);
		istringstream words(text);
		while(words >> word){
			string word_processed;
			remove_copy_if(word.begin(), word.end(), std::back_inserter(word_processed), ispunct);
			auto &line = wordmap[word_processed];
			if(!line) line.reset(new set<line_no>);
			line->insert(lineNum);
		}
	}
}

QueryResult TextQuery::query(const string& word) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto found = wordmap.find(word);
	if(found != wordmap.end()){
		return QueryResult(word, found->second, file);
	} else {
		return QueryResult(word, nodata, file);
	}
}

string postfix(const string& word, const string& s, StrBlob::size_type size){
	return (size > 1) ? word : (word + s);
}

void print(ostream& os, QueryResult& result){
	auto size = (result.lines)->size();
	os << result.search_word << " occurs " << size << postfix(" time", "s", size) << endl;
	for(auto l : *(result.lines)){
		os << "(line " << l << ")" << (result.file).child(l-1) << endl;
	}
}


#endif