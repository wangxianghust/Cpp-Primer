#include <iostream>

using namespace std;

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a,b;
	a = 2;
	b = 3;
	cout << "a is  " << a << "  b is  " << b << endl;
	swap(&a,&b);
	cout << "a is  " << a << "  b is  " << b << endl;
}