#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_map>

// using namespace std;

using std::string;
using std::cin;
using std::endl;
using std::cout;
using std::unordered_map;
using std::size_t;
using std::cout;

// using namespace std;

using std::remove_if;


auto newstrip(string &str) -> string const &{
	for(auto & ch : str){
		ch = tolower(ch);
	}

	// str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());

	str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
	return str;
}

int main(){
	unordered_map<string, size_t> word_count;
	string word;
	while(cin >> word){
		++word_count[newstrip(word)];
	}

	for(const auto &w : word_count){
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}


}