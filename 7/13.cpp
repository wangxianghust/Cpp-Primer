#include <iostream>
#include <string.h>
#include "E11.h"

using namespace std;

int main() {
	Sales_data total(cin);
	if(!total.isbn().empty()) {
		istream &is = cin;
		while(is) {
			Sales_data trans(is);
			if(total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(cout, total);
				total = trans;
			}	
		}
		print(cout, total);
	} else {
		cerr << "No data !" << endl;
	}

}