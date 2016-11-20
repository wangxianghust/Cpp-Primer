#include <iostream>

using namespace std;

void f() {
	cout << "void" << endl;
}

void f(int a) {
	cout << "int : " << a << endl;
}

void f(int a, int b) {
	cout << "two int : " << a << " " << b << endl;
}

void f(double a, double b = 3.14) {
	cout << "two double : " << a << " " << b << endl;
}

int main() {
	// f(2.56,42);
	f(42);
	f(42,0);
	f(2.56);
	f(2.52,5.25);
}