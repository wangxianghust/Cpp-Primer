#include <iostream>
using std::endl;
using std::cout;

template<typename T, unsigned size>
constexpr unsigned getSize(const T (&arr)[size]){
    return size;
}

int main(){
   int a[] = {1,2,3,4,5,};
   cout << getSize(a) << endl; 
   char b[] = "ac";
   cout << getSize(b) << endl;
}
