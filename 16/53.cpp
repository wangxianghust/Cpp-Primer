#include <iostream>
#include <string>

using namespace std;

template <typename T>
ostream& print(ostream& os, const T &t){
    return os << t << " |||";
}

template <typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest){
    os << t << "--->";
    return print(os, rest...);
}

int main(){
    int i = 0;
    double d = 1.2;
    string s("hello");

    print(cout, i);
    cout << endl;
    print(cout, i, d);
    cout << endl;
    print(cout, i, d, s, 555, "world");
    cout << endl;
}
