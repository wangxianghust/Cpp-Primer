#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	if(0 == num2) {
		throw runtime_error("divisor is 0");
	}
	cout << num1/num2 << endl;
	return 0;
}