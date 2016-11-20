#include <iostream>
#include "E13.h"

using std::cout;
using std::endl;

int main(){
	HasPtr hp(string("hello"));
	HasPtr hp1(string("test"));
	HasPtr hp2(string("test2"));
	auto p = hp;
	cout << p.getI() << "--->" << p.getString() << endl;
}