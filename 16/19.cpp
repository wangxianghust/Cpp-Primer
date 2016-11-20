#include <iostream>
#include <vector>
#include <list>
using std::list;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

//template<typename T, class V>
//void print(V<T>& v){
//    auto size_type = typename V::size_type;
//    auto size = v.size();
//    for(auto i = size_type(); i < size; ++i){
//        cout << v[i] << endl;
//    }
//}

template <typename Containner>
ostream& print(const Containner& v, ostream& os){
    for(typename Containner::size_type i = 0; i < v.size(); ++i){
        os << v[i] << endl;
    }
    return os;
}

template <typename Containner>
ostream& print2(const Containner& v, ostream& os){
    for(auto begin = v.begin(); begin != v.end(); ++begin){
        os << *begin << endl;
    }
    return os;
}

int main(){
    vector<int> l {1,2,3,4,5};
    vector<bool> v {1,1,0,0,1};
    print(l, cout);
    print(v, cout);
    list<double> d {1.2,4,2,5.8};
    print2(d,cout);
    print2(l,cout);
}
