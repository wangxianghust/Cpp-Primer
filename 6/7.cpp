#include <iostream>

using namespace std;

int generate() {
	// static size_t cnt = 0;
	size_t cnt = 0;
	cout << cnt << endl;
	return cnt ++;
}

int main() {
	for (int i = 0; i < 10; ++i) {
		generate();
		// cout << cnt << endl;
	}
}