#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main()
{
    // vector<int> v;
    // int e;
    vector<string> v;
    string e;
    while( cin >> e && e != "eof")
    {
    	v.push_back(e);
    }    
    for (auto i : v)
    	cout << i << "    ";
    cout << endl;
    cout << typeid(v).name();
    return 0;
}
