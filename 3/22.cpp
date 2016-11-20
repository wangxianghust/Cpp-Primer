#include <string.h>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::isalpha;

int main() {
	vector<string> text;
	for (string line; getline(cin,line,'#'); text.push_back(line));

	for (auto &word : text) {
		for (auto &ch : word) {
			if (isalpha(ch)) {
				ch = toupper(ch);
			}
		}
		cout << word << " ";
	}
	return 0;
}
