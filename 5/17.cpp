#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	std::vector<int> v1;
	std::vector<int> v2;

	v1 = {1,2,3};
	v2 = {1,3,4,6};
	int Flag =1;
	for (auto beg1 = v1.begin(), beg2 = v2.begin(); beg1 != v1.end() && beg2 != v2.end(); ++beg1, ++beg2) {
		if (*beg1 != *beg2) {
			Flag = 0;
		}
	}
	if (Flag == 1) {
		if (v1.size() < v2.size()) {
			cout << "v1 is the prefix of the v2" << endl;
		} else {
			cout << "v2 is the prefix of the v1" << endl;	
		}
	} else {
		cout << "There is no relation of two vector" << endl;
	}
}