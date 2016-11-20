#include <iostream>
#include <string.h>

using namespace std;

inline bool isShorter(const string a, const string b) {
	return (a.size() < b.size());
}

int main() {
	string a = "hello";
	string b = "as";
	cout << isShorter(a,b) << endl;
}