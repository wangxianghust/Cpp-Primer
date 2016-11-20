#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using std::cout;
using std::map;
using std::pair;
using std::cin;
using std::vector;
using std::endl;
using std::string;
using Families = map<string, vector<pair<string, string>> >;

auto make_families() -> Families{
	Families families;
	for(string lastname; cout << "lastname\n" , cin >> lastname && lastname != "eof";)
		for(string firstname, birthday; cout << "firstname and birthday\n" , cin >> firstname >> birthday&& firstname != "eof";){
			families[lastname].push_back({firstname, birthday});
		}
	return families;
}

void print(Families families){
	for(auto &family : families){
		cout << "The family name is : " << family.first << endl;
		cout << "The first name is : ";
		for(auto &element : family.second){
			cout << element.first << " birthday is " << element.second << endl;
		}
	}
}

int main(){
	print(make_families());
}