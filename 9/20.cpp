#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

void print(deque<int> d, string s) {
	cout << "The output of " << s << endl;
	for(auto i : d) {
		cout << i << endl;
	}
}

int main() {
	vector<int> v = {1,2,3,4,5,6,7,8,9,100,125};
	deque<int> d_odd, d_even;
	auto iter = v.begin();
	while(iter != v.end()) {
		if (*iter % 2) {
			d_odd.push_back(*iter);
		} else {
			d_even.push_back(*iter);
		}
		++ iter;
	}
	
	print(d_even, "even");
	print(d_odd, "odd");
}