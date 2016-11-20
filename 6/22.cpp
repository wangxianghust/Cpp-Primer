#include <iostream>

using namespace std;

void swap(int *&a, int *&b) {
	int *tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int *c, *d;
	for(int a, b; cin >> a >> b; ) {
		c = &a;
		d = &b;
		cout << c << "  " << d << endl;
		swap(c, d);
		cout << c << "  " << d << endl;
		cout << *c << "  " << *d << endl; 
	}
}