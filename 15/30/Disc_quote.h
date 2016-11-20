#ifndef Disc_quote_H
#define Disc_quote_H

#include "Quote.h"

class Disc_quote : public Quote{
    public:
        Disc_quote() = default;
        Disc_quote(const string& no, double price, size_t q, double dis):
            Quote(no, price),quantity(q), discount(dis){}
        double net_price(size_t n) const = 0;
    protected:
        size_t quantity;
        double discount;
};

#endif

