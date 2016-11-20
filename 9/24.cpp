#include <iostream>
#include <vector>

using namespace std;

int main() {
	// vector<int> v = {1,2,3,5,6};
	vector<int> v;
	// cout << v.at(0) << endl;
	// cout << v[0] << endl;
	cout << v.front() << endl;
	cout << *v.begin() << endl;
}