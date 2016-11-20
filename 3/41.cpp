#include <iostream>
#include <cstring>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
using std::vector;

int main() {
	int a[] = {1,2,3,6,9};
	vector<int> v;
	for (auto i : a) {
		cout << i << endl;
		v.push_back(i);
	}
	cout << "------top is array,bottom is vector-------" << endl;
	for (auto i : v) {
		cout << i << endl;
	}

	const int size = v.size();
	int b[size];
	for (int j = 0; j != size; ++j) {
		b[j] = v[j];
	}
	cout << "------now is vector to array------" << endl;
	for (auto i : b) {
		cout << i << endl;
	}
}