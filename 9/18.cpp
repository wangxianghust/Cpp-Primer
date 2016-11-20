#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	string s;
	cout << "input the word : " << endl;
	cin >> s;
	deque<char> d;
	d.insert(d.begin(), s.begin(), s.end());

	for(auto i : d) {
		cout << i << " ";
	}

	cout << endl;
}