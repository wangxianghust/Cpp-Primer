#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	// for(int i, j; cin >> i >> j; cout << "i : " << i << " j : " << j << endl) {
	// 	swap(i, j);
	// }
	const int a = 0;
	// a = 0;
	cout << a << endl;
}