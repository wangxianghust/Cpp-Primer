#include <iostream>

using namespace std;


int main() {
	
	int a = 2;
	int capture = 5;	// It must definate the capture firstly
	auto f = [capture](int a) -> int { return a + capture;};
	cout << f(a) << endl;
}