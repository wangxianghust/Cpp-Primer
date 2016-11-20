#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::string;

int main() {
	int i;
	
	while(cin >> i && i != 100) {
		string final;
		final = (i>90) ? "high pass" 
					   : (i > 70) ? "pass"
					   : (i > 60) ? "low pass" : "fail";

		cout << final <<endl;

		cout << "-------" << endl;
		string final2;
		if (i > 90) {
			final2 = "high pass";
		} else if (i > 70) {
			final2 = "pass";
		} else if (i > 60) {
			final2 = "low pass";
		} else {
			final2 = "fail";
		}

		cout << final2 << endl;
	}

}