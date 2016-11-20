#include "E2.h"

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
