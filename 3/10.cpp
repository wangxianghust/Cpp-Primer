#include <iostream>
#include <stdlib.h>
#include <string.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string str("a,simple! #string");
    
    // for (auto &c  : str)
    // 	if ( !ispunct(c) )
    // 		cout << c;
    
    for ( auto &c : str)
    	if ( ispunct(c) )
    		c = ' ';
    cout << str << endl;
    return 0;
}
