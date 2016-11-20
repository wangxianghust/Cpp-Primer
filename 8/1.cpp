#include <iostream>
#include <string>

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
	istream &is = func(cin);
	cout << is.rdstate() << endl;
	cout << "is good : " << is.good() << endl;
}