#ifndef Bulk_quote_H
#define Bulk_quote_H
#include "Quote.h"

class Bulk_quote : public Quote{
    public:
        Bulk_quote() { cout << "Bulk_quote default constructor" << endl; }
        Bulk_quote(const string& b, double p, size_t m, double dis):
            Quote(b, p), min_qyt(m), discount(dis) { cout << "Bulk_quote constructor" << endl; }
        double net_price(size_t n) const override;
        ~Bulk_quote() { cout << "Bulk_quote destructor" << endl; }
    private:
        size_t min_qyt;
        double discount;
};

double Bulk_quote::net_price(size_t n) const {
    return (n > min_qyt) ? n * price * discount : n * price;
}

#endif

