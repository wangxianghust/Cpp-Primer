#include "E58.h"
#include <iostream>
using namespace std;

int main() {
	Example::vec.push_back(10.5);
	cout << Example::vec.back() << endl;
	cout << Example::rate << endl;
	cout << Example::vecSize << endl;
}