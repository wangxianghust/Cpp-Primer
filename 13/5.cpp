#include "E5.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	HasPtr hp(string("wangxiang"));
	cout << hp.getI() << "--->" << hp.getString() << endl;
	HasPtr test(hp);
	cout << hp.getI() + 1 << "--->" << hp.getString() << endl;
}