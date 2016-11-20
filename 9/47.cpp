#include <iostream>
#include <string>

using namespace std;

int main() {
	string s("ab2c3d7R4E6");
	string number("0123456789");
	string Num;
	string Alpha;
	string::size_type pos = 0;
	while( (pos = s.find_first_of(number, pos)) != string::npos) {
		// string tmp = s[pos];
		// Num.insert(s.size(), tmp);
		Num.push_back(s[pos]);
		++pos;
	}
	cout << Num << endl;
	cout << "----------" << endl;

	pos = 0;
	while( (pos = s.find_first_not_of(number, pos)) != string::npos) {
		// string tmp = s[pos];
		// Num.insert(s.size(), tmp);
		Alpha.push_back(s[pos]);
		++pos;
	}
	cout << Alpha << endl;
}
