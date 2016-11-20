#include "E47.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

void foo(String x){
	cout << x.c_str() << endl;
}

void bar(const String& x){
	cout << x.c_str() << endl;
}

int main(){
	vector<String> v;
	// const char* s = "Hello";
	// String st(s);
	// for(int i = 0; i < 10; ++i){
	// 	v.push_back(st);
	// }
	char text[] = "world";

	String s0;
	String s1("hello");
	String s2(s1);
	String s3 = s1;
	String s4(text);
}