#ifndef E32_H
#define E32_H

#include "E19_3.h"
#include <set>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

using std::set;
using std::ifstream;
using std::istringstream;
using std::ostream;
using std::map;
using std::shared_ptr;

class QueryResult;
class TextQuery{
friend class QueryResult;
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery();
	TextQuery(ifstream&);
	QueryResult query(string) const;
private:
	// string serch_word;
	StrBlob text; // vector<string> to save every line, the shared data
	shared_ptr<set<line_no>> lines;  // the search word is in these lines
	map<string, shared_ptr<set<line_no>>> wm; 
};

// TextQuery::TextQuery(ifstream& input){
// 	string text_;
// 	line_no lineNum = 0;
// 	while(getline(input, text_)){
// 		text.push_back(text_);
// 		++ lineNum;
// 		istringstream line(text_);
// 		string word;
// 		while(line >> word){
// 			auto map_it = wm.find(word);
// 			if(map_it != wm.end()){
// 				wm[word]->insert(lineNum);
// 			} else {
// 				shared_ptr<set<line_no>> line_set;
// 				line_set->insert(lineNum);
// 				wm.insert({word, line_set});
// 			}
// 		}
// 	}	
// }


TextQuery::TextQuery(ifstream& input){
	string text_;
	line_no lineNum = 0;
	while(getline(input, text_)){
		text.push_back(text_);
		++ lineNum;
		istringstream line(text_);
		string word;
		while(line >> word){
			// auto map_it = wm.find(word);
			// if(map_it != wm.end()){
			// 	wm[word]->insert(lineNum);
			// } else {
			// 	shared_ptr<set<line_no>> line_set;
			// 	line_set->insert(lineNum);
			// 	wm.insert({word, line_set});
			// }
			string word_process;
			remove_copy_if(word.begin(), word.end(), std::back_inserter(word_process), ispunct);
			auto &nos = wm[word_process];
			if( !nos ){
				nos.reset(new set<line_no>);
			}
			nos->insert(lineNum);
			// word_process.clear();
		}
	}	
}


class QueryResult{
friend void print(ostream& , QueryResult&);
public:
	using line_no = vector<string>::size_type;
	QueryResult(string word, shared_ptr<set<line_no>> lines_, const StrBlob& text_):search_word(word),lines(lines_),text(text_) {}
private:
	string search_word;
	shared_ptr<set<line_no>> lines;  // the search word is in these lines
	StrBlob text; // vector<string> to save every line, the shared data
};

QueryResult TextQuery::query(string word) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	// QueryResult result;
	auto map_it = wm.find(word);
	if(map_it != wm.end()){
		return QueryResult(word, map_it->second, text);
	} else {
		return QueryResult(word, nodata, text);
	}
}

string make_postfix(int count, const string& word, const string& s){
	return (count > 1) ? (word + s) : word;
}

void print(ostream& os, QueryResult& result){
	int size = (result.lines)->size();
	os << result.search_word << " occurs " << size << make_postfix(size, string(" time"), string("s")) << endl;
	for(auto line : *(result.lines)){
		os << "(line " << line << ") " << (result.text).child(line-1) << endl;
	}
}

#endif 