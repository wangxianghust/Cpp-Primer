#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main() {
	list<string> v;
	string c;
	cout << "Input the vector" << endl;
	while(cin >> c && c != "eof"){
		v.push_back(c);
	}

	cout << "Input the number" << endl;
	string m;
	cin >> m;
	auto result = count(v.cbegin(), v.cend(), m);
	cout << "The " << m << " appears " << result << " times" << endl;
}