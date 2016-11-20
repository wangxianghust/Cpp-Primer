#ifndef E2_H
#define E2_H

#include <iostream>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

class Sales_data{
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
   public:
       Sales_data() = default;
       Sales_data(const string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(n*p){}
       Sales_data(const string &s):bookNo(s){}
       Sales_data(std::istream&, Sales_data& item);
       string isbn() const { return bookNo; }
       Sales_data& operator+=(const Sales_data&);
   private:
       double avg_price() const;
       string bookNo;
       unsigned units_sold = 0.0;
       double revenue = 0.0;
};

    istream& operator>>(istream&, Sales_data&);
    ostream& operator<<(ostream&, const Sales_data&);
    Sales_data operator+(const Sales_data&, const Sales_data&);

    double Sales_data::avg_price() const {
        return units_sold ? revenue/units_sold : 0;
    }


istream& operator>>(istream& is, Sales_data& item){
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if(is){
        item.revenue = price * item.units_sold;
    } else {
        item = Sales_data();
    }
    return is;
}

ostream& operator<<(ostream& os, const Sales_data& item){
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs){
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

#endif
