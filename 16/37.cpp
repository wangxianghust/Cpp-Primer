#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

template<typename T>
auto max(T s, T v){
    return (s>v) ? s : v;
}

int main(){
    std::cout << max(3,5) << std::endl;
    auto t = max<double>(3.1,5);
    cout << typeid(t).name() << endl;
}
