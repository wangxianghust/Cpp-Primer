#include <iostream>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	const char ca[] = {'h','e','l'};
	const char *cp = ca;
	/*
	for (int i = 0; i < 5; i++) {
		cout << *cp << endl;
		++cp;
	}
	*/

	while(*cp) {
		cout << *cp << endl;
		++cp;
	}

	const string ca_string = "hello";
}