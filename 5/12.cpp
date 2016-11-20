#include <iostream>
#include <string>

using namespace::std;

int main() {
	unsigned ff = 0, fi = 0, fl = 0, other = 0;
	char ch;
	char prefix = '\0';
	while (cin >> noskipws >> ch && ch != '1') {
		switch(ch) {
			case 'f' :
			if(prefix == 'f')++ff;
			break;

			case 'i' :
			if(prefix == 'f')++fi;
			break;

			case 'l' :
			if(prefix == 'f')++fl;
			break;

			default :
			++other;
			break;
		}
		prefix = ch;
	}
	cout << "ff : " << ff
		 << " fi : " << fi
		 << " fl : " << fl
		 << " other : " << other << endl;
}