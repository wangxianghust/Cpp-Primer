#include "E49_String.h"

#include <iostream>
#include <vector>
using std::vector;

using std::cin;
using std::cout;
using std::endl;

String baz(){
	String ret("world");
	return ret;
}

void print(const String& s){
	for(auto i : s){
		cout << i << "";
	}
	cout << endl << "---";
}

int main(){
	const char* s = "hello, world";
	String st(s);
	String stt;
	stt = st;

	String sttt;
	// baz();
	stt = baz();
}