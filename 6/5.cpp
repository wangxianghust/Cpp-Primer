#include <iostream>

using namespace std;

int abs(int i) {
	return (i > 0) ? i : -i;
}

int main() {
	int i;

	while(cin >> i) {
		cout << abs(i) << endl;
	}
}