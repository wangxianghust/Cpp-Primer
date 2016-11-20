#include "E6.h"

using namespace std;

int main() {
	Sales_data total;
	if(read(cin, total)) {
		Sales_data trans;
		while(read(cin, trans)) {
			if(total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total);
	} else {
		cerr << "No data" << endl;
	}
}