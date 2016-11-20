#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename T>
void print(vector<T> v) {
	for(auto i : v) {
		cout << i << endl;
	}
}

int main() {
	std::vector<int> v = {1,2,3,4,5};
	vector<int> v1(v);
	vector<double> v2(v.begin(), v.end());
	vector<double> v3 = {1.2, 3.2, 2.3, 5.0};
	// vector<string> v4 = (v3.begin(), v3.end());

	print(v1);
	cout << "-------" << endl;
	print(v2);
	cout << "-------" << endl;
	print(v3);
	cout << "-------" << endl;
	// print(v4);
}
