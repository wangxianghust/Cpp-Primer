#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

forward_list<string> func(forward_list<string> &fl, string &flag, string &ins) {
	auto prev = fl.before_begin();
	auto curr = fl.begin();
	for( ; curr != fl.end(); prev = curr ++) {
		if(*curr == flag) {
			fl.insert_after(curr, ins);
			break;
		} 
	}

	fl.insert_after(prev, ins);

	return fl;
}

int main() {
	forward_list<string> fl = {"aa", "bb", "cc"};
	string flag, ins;
	cout << "input flag : " << endl;
	cin >> flag;
	cout << "input insert string : " << endl;
	cin >> ins;
	auto result = func(fl, flag, ins);
	for(auto i : result) {
		cout << i << " ";
	}
	cout << endl;
	cout << "fl : " << endl;
	for(auto i : fl) {
		cout << i << " ";
	}
}