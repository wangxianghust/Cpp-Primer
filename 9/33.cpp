#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v = {1,2,3,4,5};
	v.reserve(50);
	auto begin = v.begin();
	while(begin != v.end()) {
		++begin;
		// begin = v.insert(begin, 100);
		v.insert(begin, 100);
		++begin;
	}

	for(auto i : v) cout << i << " ";
	cout << endl;
}