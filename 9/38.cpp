#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<int> v, string info) {
	cout << "-------- " << info << " --------" << endl;
	cout << "the size of the vector is : " << v.size() << endl;
	cout << "the capacity of the vector is : " << v.capacity() << endl;
	for(auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v;
	v.reserve(10);
	print(v, "v is null");
	for(vector<int>::size_type ix = 0; ix != 24; ++ix) {
		v.push_back(ix);
	}
	print(v, "Initial");
	v.push_back(123);
	v.push_back(123);
	print(v, "Add one more");
	v.reserve(30);
	print(v, "reserve again");
	v.resize(2*v.size());
	print(v, "resize the vector");
	v.shrink_to_fit();
	print(v, "shrink_to_fit");
	v.reserve(100);
	print(v, "reserve again");
}