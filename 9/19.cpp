#include <iostream>
#include <list>

using namespace std;

int main() {
	list<string> l;
	for(string s; cin >> s; s != "eof") {
		l.push_back(s);
	}

	for(auto i = l.cbegin(); i != l.cend(); ++ i) {
		cout << *i << " ";
	}

	cout << endl;
}