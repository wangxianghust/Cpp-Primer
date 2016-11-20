#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    const string s = "Keep out!";
    for ( auto &c : s )
    {
    	cout << typeid(c).name() ;
    }
    	string a;
    	cout << typeid(a).name();
    return 0;
}
