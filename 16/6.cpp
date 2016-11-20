#include <string>
#include <iostream>
using std::string;


template<typename T, unsigned size>
T* begin_(T (&arr)[size]){
    return arr;
}


template<typename T, unsigned size>
T* end_(T (&arr)[size]){
    return arr + size;
}

template<typename T, unsigned size>
T test(const T (&arr)[size]){
    return *(arr + size -1);
}

int main(){
    int a[] = {1,2,3,4,5};
    std::cout << *begin_(a) + 1 << std::endl;
    std::cout << *(end_(a) - 1)  << std::endl;
    std::cout << test(a)  << std::endl;

}
