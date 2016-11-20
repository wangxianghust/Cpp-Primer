#ifndef E26_H
#define E26_H

#include <iostream>
#include <string.h>

using namespace std;

class Sales_data;
istream &read(istream &is, Sales_data &item);

class Sales_data
{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream &os, const Sales_data &item);
friend istream &read(istream &is, Sales_data &item);
public:
	Sales_data() : units_sold(0), revenue(0) {}
	Sales_data(const string &s) : bookNo(s) {}
	Sales_data(const string &s, unsigned u, double n) : bookNo(s), units_sold(u), revenue(u*n) {}
	Sales_data(istream &);

	string isbn() const {return bookNo;}
	Sales_data &combine(const Sales_data &);

private:
	inline double avg_price() const;
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline
double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}
// non-member function
istream &read(istream &is, Sales_data &item);

ostream &print(ostream &os, const Sales_data &item) ;

// member functions
// Sales_data& Sales_data::combine(const Sales_data& rhs) ;

// Sales_data::Sales_data(istream &is) ;

Sales_data add(const Sales_data&, const Sales_data&);

#endif