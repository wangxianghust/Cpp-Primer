#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int>::const_iterator i, std::vector<int>::const_iterator j) {
	if(i != j) {
		cout << *i << endl;
		print(++i, j);
	}
}

int main() {
	std::vector<int> v = {1,2,3,4,5};
	auto i = v.cbegin();
	auto j = v.cend();
	print(i, j);
}