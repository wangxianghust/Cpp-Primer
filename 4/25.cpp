#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int main() {
	int q;
	std::vector<int> v;
	q = ~'q'<<6;
	cout << q << endl;
	/*while (q != 0) {
		int i = q%2;
		q = q / 2;
		v.push_back(i);
	}
	*/

	bitset<sizeof(int)*8> a(q);
	cout << a << endl;


	for (auto i : v) {
		cout << i << endl;
	}
}