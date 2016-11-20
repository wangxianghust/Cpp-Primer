#include <iostream>
#include <vector>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {
	vector<string> v = {"hello ","world"};
	for (auto it = v.begin(); it != v.end();) {
		cout << it++->empty() << endl;
	}
}