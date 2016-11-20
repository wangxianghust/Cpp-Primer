#include <iostream>
using std::cout;
using std::endl;
#include <typeinfo>

template <typename T> void f(T){
    cout << "1--f(T) " << typeid(T).name() << endl;
}

template <typename T> void f(const T*){
    cout <<  "2--f(const T*) " << typeid(T).name()  << endl;
}

template <typename T> void g(T){
    cout << "3--g(T) " << typeid(T).name() << endl;
    
}

template <typename T> void g(T*){
    cout << "4--g(const T*) " << typeid(T).name() << endl;
}

int main(){
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    cout << typeid(i).name() << endl;
    cout << typeid(p).name() << endl;
    cout << typeid(ci).name() << endl;
    cout << typeid(p2).name() << endl;
    g(42);
    g(p);
    g(ci);
    g(p2);

    f(42);
    f(p);
    f(ci);
    f(p2);
}
