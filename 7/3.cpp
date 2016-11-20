#include <iostream>
#include "E2.h"

using namespace std;

int main() {
	Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if(total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				cout << "result : " << total.bookNo << " " << total.units_sold << " " << total.revenue;
				total = trans;
			}
		}
		cout << "result : " << total.bookNo << " " << total.units_sold << " " << total.revenue;
	} else {
		cerr << "No data " << endl;
	}
}