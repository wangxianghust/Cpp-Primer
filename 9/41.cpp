#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<char> v = {'h', 'e', 'l', 'l', 'o'};
	string s(v.begin(), v.end());

	for(auto i : s) {
		cout << i << endl;
	}
	cout << s << endl;
}
