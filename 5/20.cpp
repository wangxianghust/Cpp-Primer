/*
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
			if (i == s) {
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
*/

#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    string read, tmp;
    while (cin >> read)
        if (read == tmp) break; else tmp = read;

    if (cin.eof())  cout << "no word was repeated." << endl;
    else            cout << read << " occurs twice in succession." << endl;

    return 0;
}