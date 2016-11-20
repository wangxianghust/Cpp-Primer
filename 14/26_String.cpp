#include <iostream>
#include "E26_String.h"
#include <vector>
using std::vector;

using std::cin;
using std::cout;
using std::endl;

int main(){
	const char* s = "hello, world";
	const String st(s);
    const char* s2 = "hello, worldd";
    const String stt(s2);
    if(st < stt){
	    cout << stt << endl;
    }
    for(auto i = 0; i< stt.size(); ++i){
        cout << stt[i] << endl;
    }
}
