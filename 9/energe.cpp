#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

void print(deque<int>::iterator begin, deque<int>::iterator end, string s) {
	cout << "The output of " << s << endl;
	for(deque<int>::iterator i = begin; i != end; ++i) {
		cout << *i << endl;
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
	}
	print(d_even.begin(), d_even.end(), "even");
	print(d_odd.begin(), d_odd.end(), "odd");
}