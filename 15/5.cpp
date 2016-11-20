#include "E5.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

double print_total(ostream &os, const Quote& item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN : " << item.isbn() << " sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main(){
    Quote q("wang",5);
    Bulk_quote bq("w",5,3,0.1);
    print_total(cout, q, 4);
    print_total(cout, bq, 4);
}
