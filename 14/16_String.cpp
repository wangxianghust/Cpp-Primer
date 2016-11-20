#include <iostream>
#include "E16_String.h"
#include <vector>
using std::vector;

using std::cin;
using std::cout;
using std::endl;

void print(const String& s){
	for(auto i : s){
		cout << i << "";
	}
}

int main(){
	const char* s = "hello, world";
	const String st(s);
    const char* s2 = "hello, world";
    const String stt(s2);
    if(st == stt){
	    cout << st << endl;
    }
}
