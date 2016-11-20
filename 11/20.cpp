#include <map>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main(){
	map<string, size_t> word_count;
	string word;
	while(cin >> word){
		auto ret = word_count.insert( {word, 1} );
		if(!ret.second){
			++((ret.first)->second);
		}
	}

	for(auto &i : word_count){
		cout << i.first << " " << i.second << endl;
	}
}
