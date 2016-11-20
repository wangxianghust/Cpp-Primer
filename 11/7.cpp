#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::cout;
using std::map;
using std::cin;
using std::vector;
using std::endl;
using std::string;
using Families = map<string, vector<string> >;

auto make_families() -> Families{
	Families families;
	for(string lastname; cout << "lastname\n" , cin >> lastname && lastname != "eof";)
		for(string firstname; cout << "firstname\n" , cin >> firstname && firstname != "eof";){
			families[lastname].push_back(firstname);
		}
	return families;
}

void print(Families families){
	for(auto &family : families){
		cout << "The family name is : " << family.first << endl;
		cout << "The first name is : ";
		for(auto &firstname : family.second){
			cout << firstname << endl;
		}
	}
}

int main(){
	print(make_families());
}