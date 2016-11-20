#include <iostream>
#include <vector>
#include <iterator>

using std::endl;
using std::cout;
using std::cin;
using std::begin;
using std::end;

int main() {
	int ia[5] = {1,2,3,4,5};
	for (int i : ia) {
		cout << i << endl;
	}

	cout << "subscripts " << endl;

	for (int i = 0; i < 5; ++i) {
		cout << ia[i] << endl;
	}

	cout << "pointers" << endl;

	for (int *beg = begin(ia); beg != end(ia); ++beg) {
		cout << *beg << endl;
	}

	cout << "done" << endl;

	using int_array = int[4];
	// typedef int int_array[5];
	int iaa[5][4] = { {1}, {2}, {3} };
	for (int_array *p = iaa; p != iaa + 5; ++p) {
		for(int *q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}

	cout << "use atuo" << endl;
	for( auto &i : iaa)
		for(auto j : i)
			cout << j << endl;
}