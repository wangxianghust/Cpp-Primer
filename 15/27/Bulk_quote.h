#ifndef Bulk_quote_H
#define Bulk_quote_H
#include "Quote.h"

class Bulk_quote : public Quote{
    public:
        using Quote::Quote;
        double net_price(size_t n) const override;
        ~Bulk_quote() { cout << "Bulk_quote destructor" << endl; }
        void getInfo() {cout << "min " << min_qyt << "discount" << discount <<" " <<  price << " test" << endl; }
    private:
        size_t min_qyt;
        double discount;
};

double Bulk_quote::net_price(size_t n) const {
    return (n > min_qyt) ? n * price * discount : n * price;
}

#endif

