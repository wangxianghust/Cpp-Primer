#include <iostream>

class Base{
    public:
        void pub_mem();
    protected:
        int prot_mem;
    private:
        char prit_men;
};

class Pub_Derv : public Base {
    public:
    void fun(Base& b) { b = *this; }
};

class Prot_Derv : protected Base {
    public:
    void fun(Base& b) { b = *this; }
};

class Prib_Derv : private Base {
    public:
    void fun(Base& b) { b = *this; }
};


class Derv_Pub : public Pub_Derv {
    public:
        void fun(Base& b) { b = *this; }
};

class Derv_Prot : public Prot_Derv {
    public:
        void fun(Base& b) { b = *this; }
};

class Derv_Prib : public Prib_Derv {
    public:
      //  void fun(Base& b) { b = *this; }
};

int main(){
    Pub_Derv d1;
    Base *p = &d1;

    Prot_Derv d2;
   // p = &d2;
   
    Prib_Derv d3;
   // p = &d3;
   
    Derv_Pub dd1;
    p = &dd1;

    Derv_Prib dd2;
   // p = &dd2;

    Derv_Prot dd3;
   // p = &dd3;

    
}
