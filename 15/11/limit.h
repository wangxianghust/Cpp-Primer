#include "E11.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

double print_total(ostream &os, const Quote& item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN : " << item.isbn() << " sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Limit_quote : public Bulk_quote{
    public:
        Limit_quote() = default;
        Limit_quote(const string& no, double price, size_t min, double dis, size_t lit):
            Bulk_quote(no, price, min, dis),limit(lit) {};
        double net_price(size_t n) const override;
        void debug() const override;
    private:
        size_t limit = 0;
};
// There include the min_qty strategy, over the min will have the discount but 
// when it over the max, the over-part is not being discount.
double Limit_quote::net_price(size_t n) const {
    if(n>limit){
        return Bulk_quote::net_price(limit) + (n-limit)*price;
    } else {
        return Bulk_quote::net_price(n);
    }
}

void Limit_quote::debug() const {
    Bulk_quote::debug();
    cout << "limit : " << limit << endl;
}
