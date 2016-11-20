#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

void fun_vector(vector<int> &l) {
	auto iter = l.begin();
	while(iter != l.end()) {
		if(*iter % 2) {
			iter = l.insert(iter, *iter++);
			iter ++;
			iter ++;
		} else {
			iter = l.erase(iter);
		}
	}
}

int main() {
	vector<int> l = {0,1,2,3,4,5,6,7,8,9};
	fun_vector(l);
	for(auto i : l) {
		cout << i << " ";
	}
	cout << "\n-----------" << endl;
}