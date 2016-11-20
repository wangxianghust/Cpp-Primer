#include <iostream>
#include <sstream>
using std::ostringstream;
using std::cout;
using std::endl;
#include <string>
using std::string;

// always declared first
template <typename T> string debug_rep(const T& t);
template <typename T> string debug_rep(T* p);
string debug_rep(const string& s);
string debug_rep(char* s);
string debug_rep(const char* s);

template<typename T> string debug_rep(const T &t){
    ostringstream ret;
    ret << "const T &t " << t;
    return ret.str();
}

template <typename T> string debug_rep(T* p){
    ostringstream ret;
    ret << "pointer: " << p;
    if(p){
        ret << "if p";
        ret << "->" ;
       // ret << debug_rep(*p);
    } else {
        ret << "null pointer";
    }
    return ret.str();
}

string debug_rep(const string &s){
    return "nontemplate--" + s ;
}

string debug_rep(char* s){
    return debug_rep(string(s));
}

string debug_rep(const char* s){
    return debug_rep(string(s));
}

int main(){
    string s("hi");
    //cout << debug_rep(s) << endl;
    // cout << debug_rep(&s) << endl;
    //const string *sp = &s;
    //cout << debug_rep(sp) << endl;
    // cout << debug_rep(s) << endl;

    cout << debug_rep("hello, world!") << endl;
}
