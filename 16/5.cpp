#include <iostream>
using std::endl;
using std::cout;

#include <string>
using std::string;

template<typename T, unsigned M>
void print_(const T (&arr)[M]){
    for(auto i : arr){
        cout << i << endl;
    }
    cout << endl;
}

int main(){
    int j[5] = {1,2,4,3,2};
    string s[3] = {"a", "vs", "vdd"};
    print_(j);
    print_(s);
}
