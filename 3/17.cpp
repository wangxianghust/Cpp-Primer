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
    vector<string> v;  
    for ( string words; cin >> words && words != "eof"; v.push_back( words ));
    for (auto i : v)
    	cout << i << "    ";
    cout << endl;
    for (auto &word : v)
    {
        for ( decltype( word.size() ) index = 0; index != word.size() && !isspace( word[index] ); ++index)
            word[index] = toupper( word[index] );
    }

     for ( decltype( v.size() ) count = 0; count != v.size(); count++ )
     {
        if ( count != 0 && count%3 == 0) cout <<  endl;
        cout << v[count] << "  ";
     }

     cout << endl;
    return 0;
}
