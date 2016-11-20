#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename T>
int count(vector<T> &container, T value){
    int num = 0;
    for(auto i : container){
        if(i == value)
            ++num;
    }
    return num;
}

template <>
int count(vector<const char*>& container, const char* value){
    int num = 0;
    for(const auto& i : container){
        if(strcmp(i, value) == 0)
            ++num;
    }
    return num;
}

int main(){
    vector<int> vi{1,1,1,2,3,4,8,94};
    vector<double> vd{1.2,1.1,1.1,1,2,5};
    vector<string> vs{"a", "abc", "abc", "d"};
    vector<const char*> vs2{"a", "abc", "abc", "d"};
    cout << "vi " << count(vi, 1) << endl;
    cout << "vd " << count(vd, 2.8) << endl;
    cout << "vs " << count(vs, string("abc")) << endl;
    cout << "vs2 " << count(vs2, "abc") << endl;
}
