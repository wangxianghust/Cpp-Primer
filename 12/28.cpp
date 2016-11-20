#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::ifstream;
using std::istringstream;

void print(map<string, set<int>> m){
	for(const auto &w : m){
		cout << w.first << " : " ;
		auto s = w.second;
		for(auto no : s){
			cout << no << " --- ";
		}
		cout << endl;
	}
}

void query(map<string, set<int>> &map){
	while(true){
		string word;
		cout << "Enter a word to search, or input 'q' to quit" << endl;
		if(!(cin >> word) || word == "q") break;
		auto found = map.find(word);
		if(found != map.cend()){
			auto result = found->second;
			size_t size = result.size();
			cout << word << " occurs " << size << ( (size > 1) ? " time" : " times") << " : ";
			for(auto no : result){
				cout << no << " --- ";
			}
			cout << endl;
		}
	}
}

int main(){
	string file("../data/storyDataFile.txt");
	ifstream input(file);
	string line;
	vector<string> Text;
	map<string, set<int> > wordMap;
	while(getline(input, line)){
		Text.push_back(line);
		cout << line << endl;
	}
	for(size_t line_no = 0; line_no < Text.size(); ++line_no){
		string line = Text[line_no];
		istringstream word_in(line);
		string word;
		string word_processed;
		while(word_in >> word){
			remove_copy_if(word.begin(), word.end(), back_inserter(word_processed), ispunct);
			wordMap[word_processed].insert(line_no);
			word_processed.clear();
		}
	}

	// print(wordMap);
	query(wordMap);


}