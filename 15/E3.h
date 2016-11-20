#ifndef E3_H
#define E3_H

#include <string>
using std::string;

class Quote{
    public:
        Quote() = default;
        Quote(string &no, double sales_price):bookNo(no),price(sales_price) {}
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

#endif
