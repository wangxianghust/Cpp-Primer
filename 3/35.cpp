#include <iostream>
#include <iterator>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;
using std::random_device;

int main() {
	random_device rd;
	int ia[10];
	for (int i = 0; i < 10; ++i) {
		ia[i] = rd();
	}

	for (auto i : ia) {
		cout << i << endl;
	}

	int *beg = begin(ia);
	int *last = end(ia);
	for (; beg != last; ++beg) {
		*beg = 0;
	}

	cout << "----------" << endl;

	for (auto i : ia) {
		cout << i << endl;
	}
}
