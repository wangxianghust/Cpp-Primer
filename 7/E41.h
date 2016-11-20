#ifndef E41_H
#define E41_H

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
	Sales_data(string s, unsigned cnt, double price) : bookNo(s), units_sold(cnt), revenue(cnt * price) 
		{ cout << "Sales_data(string s, unsigned cnt, double price)" << endl; }
	Sales_data() : Sales_data("", 0, 0) { cout << "Sales_data()" << endl; }
	Sales_data(const string &s) : Sales_data(s, 0, 0) { cout << "Sales_data(const string &s)" << endl; }
	Sales_data(istream &is) ;

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