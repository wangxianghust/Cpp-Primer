#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	vector<string> v;
	bool flag = 0;
	while ( cin >> s && s != "eof") {
		for (auto i : v) {
			if (i == s && isupper(s[0])) {
				flag = 1;
				break;
			}
		}
		if (1 == flag) {
			cout << s << " occurs twice" << endl;
			break;
		}
		v.push_back(s);
	}
	if (0 == flag) {
		cout << "no word was repeated !" << endl;
	}
}