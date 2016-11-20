#include <iostream>

using namespace std;

void reset(const int &i) {
	// i = 0;
	cout << i << endl;
}

int main() {
	int a = 3;
	while(cin >> a) {
		reset(a);
		cout << a << endl;
	}
}