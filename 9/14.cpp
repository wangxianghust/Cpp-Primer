#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main() {
	list<const char*> l = {"wang", "xiang", "test"};
	vector<string> v;
	v.assign(l.cbegin(), l.cend());

	for(auto i : v) {
		cout << i << endl;
	}
}

