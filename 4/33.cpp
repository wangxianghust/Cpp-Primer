#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x = 5;
	int y = 15;
	cout << (1 ? ++x, ++y : --x, --y) << endl;
	cout << (0 ? ++x, ++y : --x, --y) << endl;
}