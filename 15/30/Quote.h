#ifndef Quote_H
#define Quote_H

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Quote{
    public:
        virtual Quote* clone() const & { return new Quote(*this);  }
        virtual Quote* clone() && { return new Quote(std::move(*this)); }
        Quote() = default;
        Quote(const string &no, double sales_price):bookNo(no),price(sales_price) {}
        virtual double net_price(size_t n) const {
            return n * price;
        }
        virtual void debug() const {
           cout << "bookNo : " << bookNo << " price : " << price << endl; 
        }
        const string& isbn() const  { return bookNo; }
        ~Quote() = default;
    private:
        string bookNo;
    protected:
        double price = 0.0;
};

#endif
