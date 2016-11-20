#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void print(std::vector<int>::const_iterator i, std::vector<int>::const_iterator j) {
	if(i != j) {
		cout << *i << endl;
		cout << "other " << (j - i) << endl;
		print(++i, j);
	}
}

int main() {
	std::vector<int> v = {1,2,3,4,5};
	// assert(v.size() == 3);
	if(v.size() != 3) {
		cerr << "Error" << __FILE__
			 <<	" : in function " << __func__ << endl;
	}
	auto i = v.cbegin();
	auto j = v.cend();
	print(i, j);
}