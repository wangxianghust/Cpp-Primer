#include <iostream>

using namespace std;

int sum(initializer_list<int> il) {
	int sum = 0;
	for(auto beg = il.begin(); beg != il.end(); ++beg) {
		sum += *beg;
	}
	return sum;
}

int main() {
	cout << sum({1,2,3}) << endl;
	cout << sum({1,2,3,4}) << endl;
	cout << sum({1,2,3,4,5}) << endl;
}