#include "E26.h"
#include <fstream>
#include <iostream>

// non-member function
ifstream &read(ifstream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ofstream &print(ofstream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

// member functions
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
} 

Sales_data::Sales_data(ifstream &is) {
	read(is, *this);
}

int main(int argc, char **argv) {
	ifstream input(argv[0]);
	ofstream output(argv[1]);

	Sales_data total;
	if(read(input,total)) {
		Sales_data trans;
		while(read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	} else
		cerr << "No data " << endl;
}