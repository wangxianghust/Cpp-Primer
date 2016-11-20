#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;
using std::find;

int main(){
	vector<string> exclude = {"the", "a", "an"};
	map<string, size_t> count_words;
	string word;
	while(cin >> word){
		if(find(exclude.begin(), exclude.end(), word) == exclude.end()){
			++count_words[word];
		}
	}

	for(auto & i : count_words){
		cout << i.first << " occurs " << i.second << endl;
	}
}