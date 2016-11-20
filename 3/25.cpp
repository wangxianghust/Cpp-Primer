#include <iostream>
#include <string.h>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	vector<unsigned int> v(11,0);
	unsigned int grades;
	auto it = v.begin();
	while(cin >> grades) {
		if(grades <= 100) {
			++(*(it + grades/10) );
		}
	}

	for(auto it2 = v.begin(); it2 != v.end(); it2++) {
		cout << *it2 << endl;
	}
}

