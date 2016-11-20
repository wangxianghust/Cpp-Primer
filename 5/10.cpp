#include <iostream>

using namespace::std;

int main() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, other = 0;
	char ch;
	while (cin >> ch && ch != '1') {
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
		 << " other : " << other << endl;
}