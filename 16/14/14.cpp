#include "E14.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
    Screen<5,2> s('w');
    std::cout << s.get(3,1) << std::endl;
    cout << s;
    Screen<5,2> t;
    cout << "input char to initialization" << endl;
    cin >> t;
    cout << t;
}


