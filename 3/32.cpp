#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main() {
	
	unsigned scores[11];
	for (auto i : scores) {
		cout << i << endl;
	}

	unsigned grade;
	while (cin >> grade) {
		if (grade <= 100) {
			++scores[grade/10];
		}
	}

	cout << "top is undefined, down is cin" << endl;
	for (auto i : scores) {
		cout << i << endl;
	}	
}