#include <iostream>
using namespace std;
#include <typeinfo>
#include <string>

template <typename T, typename... Args>
void foo(const T &t, const Args&... rest){
    cout << sizeof...(Args) << endl;
    cout << sizeof...(rest) << endl;
}

int main(){
    int i = 0;
    double d = 1.2;
    string s = "How are you";
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");
}
