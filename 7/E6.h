#ifndef E6_H
#define E6_H

#include <iostream>
#include <string.h>

using namespace std;

struct Sales_data
{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data&);
};

Sales_data add(const Sales_data &, const Sales_data &);
istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
} 

istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

#endif