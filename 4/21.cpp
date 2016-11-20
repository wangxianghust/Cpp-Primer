#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::vector<int> v = {2,3,6,8,89};
	for (auto &i : v) {
		(i%2==1) ? (i = 2*i) : (i=i);
	}

	for (auto i : v) {
		cout << i << endl;
	}
}