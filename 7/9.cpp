#include <iostream>
#include "E5.h"
using namespace std;

int main() {
	Person p;
	while(read(cin, p)){
		if(p.name == "name") {
			break;
		}
		print(cout, p);
		cout << "-----test-----" << endl;
	}
	// read(cin, p);
	// cout << "-----test-----" << endl;
	// print(cout, p);
}