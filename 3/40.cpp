#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main() {
	char a1[] = "wang , ";
	char a2[] = "hello, world!";
	int len1 = strlen(a1);
	int len2 = strlen(a2);

	const int len = len1 + len2;
	char a3[len];
	strcpy(a3,a1);
	strcat(a3,a2);

	for (auto i : a3) {
		cout << i << endl;
	}
}
