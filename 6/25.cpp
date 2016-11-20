#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	char s1[] = "test";//string(argv[0]);
	char s2[] = "ok";//string(argv[1]);
	string str;
	cout << strcat(s1, s2) << endl;
	cout << argc << endl;
	for(int i = 0; i != argc; ++i){
		str += string(argv[i]) + " ";
	}
	cout << str << endl;
}