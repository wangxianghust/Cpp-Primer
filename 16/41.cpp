#include <iostream>
using std::endl;
using std::cout;

template<typename T, typename T1>
auto sum(T s, T1 v) -> decltype(s + v){
    return s + v;
}

int main(){
    auto s = sum(1112223333333,55555555555555555);
    cout << "sum(1112223333333,55555555555555555)"
        << s << endl;
}

