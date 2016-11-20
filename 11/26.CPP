#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <typeinfo>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main(){
	map<string, int> m = { {"ab", 1}, {"dc", 2} };
	using KeyType = map<string, int>::key_type;

	cout << "key type is : " << typeid(KeyType).name() << endl;
	cout << "return type is : " << typeid(m["ab"]).name() << endl;
}