#include <iostream>
#include <string>

using namespace std;

int main() {
	string rsp;
	do {
		string s1, s2;
		cout << "Please input two strings :" << endl;
		if(cin >> s1 >> s2) {
			bool result = (s1.size() >= s2.size());
			if (result) {
				cout << "s2 is smaller than s1" << endl;
			} else {
				cout << "s1 is smaller than s2" << endl;
			}
			cout << "More? Enter yes or no : ";
			cin >> rsp;
		}
	} while (tolower(rsp[0]) == 'y');
	return 0;
}