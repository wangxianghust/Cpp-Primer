#ifndef Limit_Quote_H
#define Limit_Quote_H

#include "Disc_quote.h"
#include "Quote.h"

class Limit_quote : public Disc_quote{
    public:
        Limit_quote() = default;
        Limit_quote(const string& no, double price, int m, double disc):
            Disc_quote(no, price, m, disc) {}
        double net_price(size_t n) const override;
};

double Limit_quote::net_price(size_t n) const {
    if(n < quantity){
        return n * (1 - discount) * price;
    } else {
        return n * price;
    }
}

#endif

