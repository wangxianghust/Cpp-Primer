#include <iostream>

using namespace std;

int factor(int i) {
	if(i > 1) {
		return factor(--i)*i;
	}
	return 1;
}

int main() {
	int i = 3;
	int result = factor(i);
	cout << result << endl;
}