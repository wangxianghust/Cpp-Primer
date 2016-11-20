#include <iostream>
#include "E44.h"
#include <vector>
using std::vector;

using std::cin;
using std::cout;
using std::endl;

void test(){
	const char* s = "wang";
	int count = 0;
	while(*s != '\0'){
		cout << *s << "---";
		++s;
		++count;
	}
	cout << endl;
	cout << count << endl;
}

void print(const String& s){
	for(auto i : s){
		cout << i << "";
	}
}

int main(){
	const char* s = "hello, world";
	const String st(s);
	print(st);
	cout << endl << "---";
	cout << st.size() << endl;
	// st.push_back('x');
	// st.push_back('x');
	print(st);
	cout << endl;
	// String stt = st;  // What is the problem when I have an assignment operator.
	// print(stt);
	cout << "<<" << endl;

	std::vector<int> v{1,2,3};
	vector<int> m = v;
	for(auto i : m){
		cout << i << endl;
	}
}