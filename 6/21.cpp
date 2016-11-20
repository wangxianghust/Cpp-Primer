#include <iostream>

using namespace std;

int large(int a, int *b) {
	return (a > *b) ? a : *b;
}

int main() {
	for(int a, b; cin >> a >> b;) {
		cout << large(a, &b) << endl;
	}
}