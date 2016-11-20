#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

struct A{
    public:
        A(istream &i= cin):is(i){}
        string operator()();
    private:
        istream& is;
};

string A::operator()(){
   string s;
   return ( getline(is, s) ) ? s : string();
}

int main(){
    A test(cin);
    cout << test() << endl;
}

