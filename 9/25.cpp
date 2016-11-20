#include <iostream>
#include <list>
#include <vector>
#include <typeinfo>

using namespace std;

int main() {
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	cout << typeid(ia).name() << endl; 	
	std::vector<int> v;
	list<int> l;
	for(auto i : ia) {
		v.push_back(i);
		l.push_back(i);
	}

	auto i = l.begin();
	while(i != l.end()) {
		if(*i % 2) {
			i = l.erase(i);
		} else {
			++ i;
		}
	}

	auto j = v.begin();
	while(j != v.end()) {
		if(*j % 2) {
			++ j;
		} else {
			j = v.erase(j);
		}
	}

	for(auto i : l) {
		cout << i << " ";
	}

	cout << endl;

	for(auto i : v) {
		cout << i << " ";
	}
}