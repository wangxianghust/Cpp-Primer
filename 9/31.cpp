#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

void fun_list(list<int> &l) {
	auto iter = l.begin();
	while(iter != l.end()) {
		if(*iter % 2) {
			iter = l.insert(iter, *iter);
			iter ++;
			iter ++;
		} else {
			iter = l.erase(iter);
		}
	}
}

void func_forward_list(forward_list<int> &fl) {
	auto prev = fl.before_begin();
	auto iter = fl.begin();
	while(iter != fl.end()) {
		if(*iter % 2) {
			iter = fl.insert_after(iter, *iter);
			prev = iter;
			iter ++;
		} else {
			iter = fl.erase_after(prev);
		}
	}
}

int main() {
	list<int> l = {0,1,2,3,4,5,6,7,8,9};
	fun_list(l);
	for(auto i : l) {
		cout << i << " ";
	}
	cout << "\n-----------" << endl;

	forward_list<int> fl = {0,1,2,3,4,5,6,7,8,9};
	func_forward_list(fl);
	for(auto i : l) {
		cout << i << " ";
	}
	cout << endl;
}