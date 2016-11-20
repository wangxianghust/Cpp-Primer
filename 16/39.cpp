#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

template<typename T>
int compare(const T& s, const T& v){
    if(s < v) return 1;
    if(v < s) return -1;
    return 0;
}
int main(){
    cout << compare<string>("aas", "ss") << endl;
}
