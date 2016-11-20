#ifndef E5_H
#define E5_H

#include <string>
using std::string;

class Quote{
    public:
        Quote() = default;
        Quote(const string &no, double sales_price):bookNo(no),price(sales_price) {}
        virtual double net_price(size_t n) const {
            return n * price;
        }
        const string& isbn() const  { return bookNo; }
        ~Quote() = default;
    private:
        string bookNo;
    protected:
        double price = 0.0;
};

class Bulk_quote : public Quote{
    public:
        Bulk_quote() = default;
        Bulk_quote(const string& no, double price, int min, double disc):
            Quote(no, price), min_qty(min), discount(disc) {}
        double net_price(size_t n) const override;
    private:
        size_t min_qty = 0;
        double discount = 0.0;
};

double Bulk_quote::net_price(size_t n) const {
    if(n > min_qty){
        return n * (1-discount) * price;
    } else {
        return n * price;
    }
}
#endif
