#include <iostream>

using namespace::std;

int main() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, other = 0, space = 0, table = 0, newlines = 0;
	char ch;
	while (cin >> noskipws >> ch && ch != '1') {
		switch(ch) {
			case 'a' : case 'A' :
			++aCnt;
			break;

			case 'e' : case 'E' :
			++eCnt;
			break;

			case 'i' : case 'I' :
			++iCnt;
			break;

			case 'o' : case 'O' :
			++oCnt;
			break;

			case 'u' : case 'U' :
			++uCnt;
			break;

			case ' ' :
			++space;
			break;

			case '\t' :
			++table;
			break;

			case '\n' :
			++newlines;
			break;

			default :
			++other;
			break;
		}
	}
	cout << "aCnt : " << aCnt
		 << " eCnt : " << eCnt
		 << " iCnt : " << iCnt
		 << " oCnt : " << oCnt
		 << " uCnt : " << uCnt 
		 << " space : " << space
		 << " table : " << table
		 << " newlines : " << newlines
		 << " other : " << other << endl;
}