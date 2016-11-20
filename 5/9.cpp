#include <iostream>

using namespace::std;

int main() {
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, other = 0;
	char ch;
	while (cin >> ch && ch != '1') {
		if (ch == 'a') {
			++aCnt;
		} else if (ch == 'e') {
			++eCnt;
		} else if(ch == 'i') {
			++iCnt;
		} else if(ch == 'o') {
			++oCnt;
		} else if (ch == 'u') {
			++uCnt;
		} else {
			++other;
		}
	}
	cout << "aCnt : " << aCnt
		 << " eCnt : " << eCnt
		 << " iCnt : " << iCnt
		 << " oCnt : " << oCnt
		 << " uCnt : " << uCnt 
		 << " other : " << other << endl;
}