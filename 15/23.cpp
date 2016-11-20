#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base{
    public:
        virtual void fun() { cout << "Base::fun()" << endl; };
};

class D1 : public Base {
    public:
        void fun() override { cout << "D1::fun()" << endl; }
        virtual void fun1() { cout << "D1::fun1()" << endl; }
};

class D2 : public D1 {
    public:
        void fun() override { cout << "D2::fun()" << endl; }
        void fun1() override { cout << "D2::fun1()" << endl; }
};

int main(){
    Base b;
    D1 d1;
    D2 d2;
    Base *bp1 = &b, *bp2 = &d1, *bp3 = &d2;
    bp1 -> fun();
    bp2 -> fun();
    bp3 -> fun();

    D1 *d1p = &d1;
    D2 *d2p = &d2;
    d1p -> fun1();
   // bp2 -> fun1();
}
