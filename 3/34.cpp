#include <iostream>
#include <typeinfo>
#include <iterator>

using std::endl;
using std::cout;
using std::cin;
using std::begin;
using std::end;

int main() {
	int ia[6] = {0,1,2,3,4,5};
	auto ia2(ia);

	int a(123);

	cout << typeid(ia2).name() << endl;
	cout << typeid(a).name() << endl;
	cout << a << endl;

	int *e = &ia[9];
	for(int *b = ia; b != e; ++b) {
		cout << *b << endl;
	}
	cout << "------cout by begin and end------" << endl;
	int *beg = begin(ia);
	int *last = end(ia);
	while(beg != last) {
		cout << *beg << endl;
		++beg;
	}

	cout << "------something about p1 and p2------" << endl;
	int *p1 = &ia[1];
	int *p2 = &ia[3];
	cout << *p1 << endl;
	cout << *p2 << endl;
	p1 += p2 - p1;
	cout << *p1 << endl;
	cout << typeid(p2-p1).name() << endl;

}


