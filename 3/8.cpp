#include <iostream>
#include <stdlib.h>
#include <string.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string str("a s");
    
    for (unsigned int i = 0; i < str.size(); ++i ) str[i] = 'Y';
    cout <<  str << endl;
    
    unsigned int j=0;
    while(j< str.size()) str[j++] = 'X';
    cout << str << endl; 

    string s;
    cout << s[0] << endl;
    // I like range for.
    return 0;
}
