#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> v;
	string s_input;
	while (cin >> s_input && s_input != "eof") {
		v.push_back(s_input);
	}
	auto beg = v.begin();
	int s_num = 1;
	int max_num = 1;
	string max_s;
	while (beg+1 != v.end()) {
		if ( *beg == *(beg + 1) ) {
			++s_num;
		} else {
			if ( s_num > max_num ) {
				max_num = s_num;
				max_s = *beg;
			}
			s_num = 1;
		}
		++beg;
	}

	if(max_num == 1) {
		cout << "no word is reapted! " << endl;
	} else {
		cout << "the word " << max_s << " occurred " << max_num << " times" << endl;
	}
}