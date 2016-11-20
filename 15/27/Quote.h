#ifndef Quote_H
#define Quote_H

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

class Quote{
    friend bool operator != (const Quote& lhs, const Quote& rhs);
    public:
        Quote() { cout << "Quote default constructor" << endl; }
        Quote(const string& book, double p):bookNo(book), price(p) { cout << "Quote constructor" << endl; }
        Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) { cout << "Quote copy" << endl; }
        Quote(const Quote&& q) : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { cout << "Quote move copy" << endl; }
        Quote& operator=(const Quote& lhs) {
            if( *this != lhs ){
                bookNo = lhs.bookNo;
                price = lhs.price;
            }
            cout << "Quote = operator" << endl;
            return *this;
        }
        string isbn() const { return bookNo; }
        virtual double net_price(size_t n) const { return n*price; }
        virtual ~Quote() { cout << "Base destructor" << endl; };
    private:
        string bookNo;
    protected:
        double price = 0.0;
};


bool operator != (const Quote&lhs, const Quote& rhs){
    return lhs.bookNo != rhs.bookNo &&
        lhs.price != rhs.price;
} 
#endif 
