#include <iostream>
#include <string>
#include "Chapter6.h"

using namespace  std;

int main() {
	int i;
	cin >> i;
	int result = fact(i);
	cout << result << endl;

	cout << "test is fact(5) equals 120 : " << endl;
	cout << boolalpha << (120 == fact(5) ) << endl;
}

int fact(int i) {
	if(1 == i) {
		return 1;
	} else {
		return fact(i-1)*i;
	}
}