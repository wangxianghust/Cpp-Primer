#include <iostream>
#include <unordered_set>
#include "Sales_data.h"

using std::unordered_multiset;
using std::cout;
using std::endl;

int main(){
    unordered_multiset<Sales_data> SDset;
    SDset.emplace("wang", 5, 5);
    SDset.emplace("hello", 1, 2);
    for(const auto ele : SDset){
        cout << "the hashcode of the item " << ele.isbn() 
            << "\n0x" << std::hex << std::hash<Sales_data>()(ele) << endl;
    }
}
