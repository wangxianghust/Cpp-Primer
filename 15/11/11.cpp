#include "E11.H"
#include "limit.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

void print_debug(const Quote& q){
    q.debug();
}

int main(){
    Quote q("quote",115);
    Bulk_quote bq("bulk",2225,3,0.1);
    Limit_quote bqq("limit", 3333, 4, 5, 6);
    cout << "====== static type ======" << endl;
    Quote &r = q;
    r.debug();
    r = bq;
    r.debug();
    r = bqq;
    r.debug();

    cout << "====== dynamic type ======" << endl;
    print_debug(q);
    print_debug(bq);
    print_debug(bqq);
}
