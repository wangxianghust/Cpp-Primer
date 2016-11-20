#include <list>
#include <forward_list>
#include <iostream>

using namespace std;

int main() {
	forward_list<int> fl = {1,2,1,5,6,7,8,9,10};
	
	auto prev = fl.before_begin();
	auto curr = fl.begin();

	while(curr != fl.end()) {
		if(*curr & 0x1) {
			cout << *curr << endl;
			curr = fl.erase_after(prev);
		} else {
			cout << "else " << *curr << endl;
			prev = curr;
			++ curr;
		}
	}

	for(auto i : fl) {
		cout << i << " ";
	}
	cout << endl;
}