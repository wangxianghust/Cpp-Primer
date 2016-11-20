#include <iostream>
#include <string>

using namespace std;

void replace_with(string &s, string &oldVal, string &newVal) {
	for(unsigned int i = 0; i != s.size(); ) {
		string tmp(s, i, oldVal.size());
		if(tmp == oldVal){
			s.replace(i, oldVal.size(), newVal);
			i += newVal.size();
		} else {
			++ i;
		}
	}

}

int main() {
	string s("I wa go to wa beijing wa he ha la ;");
	cout << s << endl;
	string oldVal;
	string newVal;
	cout << "input oldVal: " << endl;
	cin >> oldVal;
	cout << "input oldVal: " << endl;
	cin >> newVal;
	cout << "-------" << endl;
	replace_with(s, oldVal, newVal);
	cout << s << endl;

}