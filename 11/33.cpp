#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::multimap;
using std::map;
using std::vector;
using std::runtime_error;
using std::ifstream;
using std::istringstream;

map<string, string> buildMap(ifstream &map_file){
	map<string, string> map;
	string key, value;
	while(map_file >> key && getline(map_file, value)){
		if(value.size() >  1) {
			map[key] = value.substr(1);
		} else{
			throw runtime_error("no rule for " + key);
		}
	}

	return map;
}

const string &transform(const string &s, const map<string, string> &m){
	auto map_it = m.find(s);
	if(map_it != m.cend()){
		return map_it->second;
	} else{
		return s;
	}
}

int main(){
	string file("../data/word_transformation.txt");
	ifstream map_file(file);
	auto map = buildMap(map_file);
	string file2("../data/given_to_transform.txt");
	ifstream to_trm(file2);
	string text;
	while(getline(to_trm, text)){
		istringstream input(text);
		string word;
		bool firstword = true;
		while(input >> word){
			if(firstword)
				cout << transform(word, map);
			else
				cout << " " << transform(word, map);
			firstword= false;
		} 
		cout << endl;
	}

}