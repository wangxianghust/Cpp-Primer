#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

template <typename T>
int compare(const T& s, const T& v){
    if(s < v) return -1;
    if(v < s) return 1;
    return 0;
}

class A{
    friend bool operator<(const A&, const A&);
    private:
        int a;
        int b;
};

bool operator<(const A& a1, const A& a2){
    return a1.a < a2.a;
}

int main(){
    cout << compare(1,2) << endl;
    cout << compare("abc","aaa") << endl;
    string s1("abc");
    string s2("aaa");
    cout << compare(s1, s2) << endl;
    vector<int> v1{1,2,3};
    vector<int> v2{1,2,3};
    cout << compare(v1, v2) << endl;
    A a1,a2;
    cout << compare(a1, a2) << endl;
}
