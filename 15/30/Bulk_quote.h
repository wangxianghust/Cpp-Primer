#ifndef Bulk_Quote_H
#define Bulk_Quote_H

#include "Disc_quote.h"
#include "Quote.h"

class Bulk_quote : public Disc_quote{
    public:
        virtual Bulk_quote* clone() const & { return new Bulk_quote(*this); }
        virtual Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
        Bulk_quote() = default;
        Bulk_quote(const string& no, double price, int m, double disc):
            Disc_quote(no, price, m, disc) {}
        double net_price(size_t n) const override;
};

double Bulk_quote::net_price(size_t n) const {
    if(n > quantity){
        return n * discount * price;
    } else {
        return n * price;
    }
}

#endif
