#include <vector>
using std::vector;
#include <string>
using std::string;
#include <list>
using std::list;
#include <iostream>
using std::cout;
using std::endl;

template <typename T, typename IT>
IT findd(const IT &begin, const IT &end, T value) {
    IT beg = begin;
    for (; beg != end; ++beg){
        if(*beg == value) {
            return beg;
        }
    }
    return beg;
}

int main(){
    vector<int> v{1,3,4,32,4,2,2,89};
    auto ret = findd(v.begin(), v.end(), 32);
    cout << *ret << endl;
    list<string> l{"abs", "a", "sc", "abc"};
    auto ls = findd(l.begin(), l.end(), "sc");
    cout << *ls << endl;
}
