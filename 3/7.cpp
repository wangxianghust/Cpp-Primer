#include <iostream>
#include <stdlib.h>
#include <string.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string str("a simple string");
    
    for (auto &c  : str)
        c = 'X';
    cout <<  str << endl;

    // I like range for.
    return 0;
}
