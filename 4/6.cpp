#include <iostream>

using std::endl;
using std::cin;
using std::cout;

int main() {
	int a;
	cin >> a;
	if (a%2 == 1) {
		std::cout << "even" << endl;
	} else {
		std::cout << "old" << endl;
	}

	cout << "--------" << endl;
	cout << (a & 0x1) << endl;
}