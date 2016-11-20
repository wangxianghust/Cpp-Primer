#include <string.h>
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	string s1 = "hust";
	string s2 = "hustwang";
	string Flag;
	if (s1 >= s2) {
		if (s1 > s2) {
			Flag = "bigger";
		} else {
			Flag = "equal";
		}
	} else {
		Flag = "small";
	}

	cout << s1 << " is " << Flag << " " << s2 << endl;
	cout << "----------" << endl;

	const char ca1[] = "hustw";
	const char ca2[] = "hust";
	int cFlag = strcmp(ca1,ca2);
	cout << ca1 << " is " << cFlag << " " << ca2 << endl; 
}
