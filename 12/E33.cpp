#include "E33.h"
#include <algorithm>


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

string postfix(const string& word, const string& s, /*StrBlob::size_type*/ int size){
	return (size > 1) ? word : (word + s);
}

void print(ostream& os, QueryResult& result){
	auto size = (result.lines)->size();
	os << result.search_word << " occurs " << size << postfix(" time", "s", size) << endl;
	for(auto l : *(result.lines)){
		os << "(line " << l << ")" << (result.file).child(l-1) << endl;
	}
}