#include "E47.h"

#include <iostream>
#include <vector>
using std::vector;

using std::cin;
using std::cout;
using std::endl;

void print(const String& s){
	for(auto i : s){
		cout << i << "";
	}
	cout << endl << "---";
}

int main(){
	const char* s = "hello, world";
	String st(s);
	// print(st);
	// String stt = st;  // What the problem is when I have an assignment operator.
	// print(stt);
	// auto stt = st;
	String stt;
	stt = st;
}