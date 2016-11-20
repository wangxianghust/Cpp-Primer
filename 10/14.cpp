#include <iostream>

using namespace std;


int main() {
	auto f = [](int a, int b) -> int { return a + b;};
	
	int a = 2;
	int b = 3;
	cout << f(a, b) << endl;
}