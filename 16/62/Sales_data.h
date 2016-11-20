#ifndef Sales_data_H
#define Sales_data_H

#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;
using std::istream;
using std::ostream;
using std::cin;

//template <class T> class std::hash;
class Sales_data{
    // friend struct std::hash<Sales_data>;
    friend std::hash<Sales_data>;
    friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);
    friend bool operator!=(const Sales_data& lhs, const Sales_data& rhs);
    friend bool operator>=(const Sales_data& lhs, const Sales_data& rhs);
    friend bool operator<=(const Sales_data& lhs, const Sales_data& rhs);
    friend bool operator>(const Sales_data& lhs, const Sales_data& rhs);
    friend bool operator<(const Sales_data& lhs, const Sales_data& rhs);
    friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
    friend istream& operator>>(istream& is, Sales_data& data);
    friend ostream& operator<<(ostream& is, const Sales_data& data);
    public:
        Sales_data() = default;
        Sales_data(const string& no, unsigned u, double unit_price):bookNo(no), units_sold(u), revenue(u*unit_price) {};
        Sales_data(const string& no):bookNo(no) {};
        Sales_data(istream&);
        string isbn() const { return bookNo; }
        Sales_data& operator+=(const Sales_data& rhs);
        Sales_data& operator=(const string& isbn);
    private:
        double avg_price() const  { return units_sold ? revenue/units_sold : 0; }
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

bool operator==(const Sales_data& lhs, const Sales_data& rhs);
bool operator!=(const Sales_data& lhs, const Sales_data& rhs);
bool operator>=(const Sales_data& lhs, const Sales_data& rhs);
bool operator<=(const Sales_data& lhs, const Sales_data& rhs);
bool operator>(const Sales_data& lhs, const Sales_data& rhs);
bool operator<(const Sales_data& lhs, const Sales_data& rhs);
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
istream& operator>>(istream& is, Sales_data& data);
ostream& operator<<(ostream& os, const Sales_data& data);

bool operator==(const Sales_data& lhs, const Sales_data& rhs){
    return (lhs.bookNo == rhs.bookNo);
}
bool operator!=(const Sales_data& lhs, const Sales_data& rhs){
    return !(lhs == rhs); 
}
bool operator>=(const Sales_data& lhs, const Sales_data& rhs){
    return !(lhs < rhs);
}
bool operator<=(const Sales_data& lhs, const Sales_data& rhs){
    return !(rhs < lhs);
}
bool operator>(const Sales_data& lhs, const Sales_data& rhs){
    return (rhs < lhs);
}
bool operator<(const Sales_data& lhs, const Sales_data& rhs){
    return (lhs.bookNo < rhs.bookNo);
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs){ // maybe there is a bookNo test to determine whether addition can be done.
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

istream& operator>>(istream& is, Sales_data& data){
    double price;
    is >> data.bookNo >> data.units_sold >> price;
    if(is){
        data.revenue = data.units_sold * price;
    } else {
        data = Sales_data();
    }
    return is;
}
ostream& operator<<(ostream& os, const Sales_data& data){
   os << "The bookNo is : " << data.bookNo << " , the units_sold is : " << data.units_sold << " revenue is " << data.revenue;
   return os;
}

Sales_data::Sales_data(istream& is){
    is >> *this;
}

Sales_data& Sales_data::operator=(const string& isbn){
    *this = Sales_data(isbn);
    return *this;
}

namespace std{
    template <>
    struct hash<Sales_data>{
            typedef size_t result_type;
            typedef Sales_data argument_type;
            size_t operator()(const Sales_data& s) const;
        };
    size_t hash<Sales_data>::operator()(const Sales_data& s) const{
        return std::hash<string>()(s.bookNo)^
            std::hash<unsigned>()(s.units_sold)^
            std::hash<double>()(s.revenue);
    }
}

#endif 
