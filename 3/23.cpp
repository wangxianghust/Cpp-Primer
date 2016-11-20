#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	std::vector<int> v(10,3);
	for (auto it = v.begin(); it != v.end(); ++it) {
		*it = 2*(*it);
	}

	for (auto c : v) {
		cout << c << endl;
	}
}