#include <sstream>
#include <iostream>
using namespace std;

istream &func (istream &is) {
	string buf;
	while( is >> buf ) {
		cout << buf << endl;
	}
	cout << "state : " << is.rdstate() << endl;
	is.clear();
	return is;
}


int main() {
	istringstream record("cin");
	func(record);
}