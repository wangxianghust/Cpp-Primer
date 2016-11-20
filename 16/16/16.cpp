#include "E16.h"

int main(){
    Vec<int> v = {1,2,3,2,3};
  //  Vec<string> v{"ad", "df", "ddd"};
    Vec<int> v2;
    v2 = v;
    cout << v.size() << endl;
    cout << v2.capacity() << endl;
    v.push_back(199);
    cout << v.size() << endl;
    v.resize(100);
    cout << v.capacity() << endl;
}
