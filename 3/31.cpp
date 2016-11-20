#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main() {
	int a[10]={};

	for (auto i : a) {
		cout << i << endl;
	}

	for (int i = 0; i < 10; i++) {
		a[i] = i;
	}

	std::vector<int> v;
	for (unsigned int i = 0; i < 10; ++i) {
		v.push_back(a[i]);
	}

	cout << "print the array :" << endl;
	for (auto i : a) cout << i << endl;
	cout << "print the vector :" << endl;
	for (auto i : v) cout << i << endl;
}