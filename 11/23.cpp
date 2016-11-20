#include <map>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::multimap;

int main(){
	multimap<string, string> family;
	string first, second;
	while(cin >> first >> second){
		// family.insert({first, second});
		family.emplace(first, second);
	}

	for(auto &i : family){
		cout << i.first << " " << i.second << endl;
	}
}