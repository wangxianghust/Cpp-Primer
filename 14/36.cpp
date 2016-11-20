#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

#include <vector>
using std::vector;

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
    vector<string> v;
    for(string str("Input test: \n"); str != ""; str = test()){
        v.push_back(str);
    }

    for(string str; !( (str = test()).empty()) ; ) v.push_back(str);

    for(auto i : v){
        cout << i << ">>>";
    }
    cout << endl;
}


