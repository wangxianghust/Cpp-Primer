#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

typedef int(*pf)(int, int);

int add(int a, int b) {
	return a+b;
}

int subtract(int a, int b) {
	return a-b;
}

int multiply(int a, int b) {
	return a*b;
}

int divide(int a, int b) {
	return a/b;
}

int main() {
	vector<pf> v = {add, subtract, multiply, divide};
	int a = 10;
	int b = 5;
	for (auto i : v) {
		cout << i(a,b) << endl;
		cout << typeid(i).name() << endl;
	}
}