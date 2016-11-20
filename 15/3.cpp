#include "E3.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

double print_total(ostream &os, const Quote& item, size_t n){
    double ret = item.net_price();
    cout << "ISBN : " << item.isbn() << " sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main(){
    
}
