#include <iostream>
#include <vector>

using namespace std;

void find_and_replace(string &s, string &oldVal, string &newVal) {
	for(unsigned int index = 0; index != s.size();){
		string tmp(s, index, oldVal.size());
		if(tmp == oldVal){
			s.erase(index, oldVal.size());
			s.insert(index, newVal);
			index = index + newVal.size();
		} else {
			++ index;
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
	find_and_replace(s, oldVal, newVal);
	cout << s << endl;

}