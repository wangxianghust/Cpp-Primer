#include <iostream>
#include <sstream>
using std::ostringstream;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::ostream;

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
        ret << debug_rep(*p);
    } else {
        ret << "null pointer";
    }
    return ret.str();
}

string debug_rep(const string &s){
    return "nontemplate-" + s ;
}

string debug_rep(char* s){
    return debug_rep(string(s));
}

string debug_rep(const char* s){
    return debug_rep(string(s));
}

template <typename T>
ostream& print(ostream& os, const T &t){
    return os << t << " |||";
}

template <typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest){
    os << t << "--->";
    return print(os, rest...);
}


template <typename... Args>
ostream& errorMsg(ostream& os, const Args&... rest){
    return print(os, debug_rep(rest)...);
}

int main(){
    string s("hi");
    int i = 0;
    double b = 1.2;

    errorMsg(std::cerr, i, b, s, "hello");
    errorMsg(std::cerr, 666);
}

