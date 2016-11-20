#include <vector>
#include <iostream>

using namespace std;

vector<int>::iterator func(vector<int> v, int ele) {
	bool flag = false;
	auto begin = v.begin();
	auto end = v.end();
	while (begin != end) {
		if(*begin == ele) {
			flag = true;
			return begin;
		}
		++begin;
	}
	if(flag == false) {
		cout << "I can not find it !" << endl;
	}
	return end;
}

int main() {
	vector<int> v1 = {1, 2, 3, 5, 6};
	vector<int> v2 = {1, 2, 7, 5, 6};
	int ele = 7;
	cout << "v1 : " << *func(v1, ele) << endl;
	cout << "v2 : " << *func(v2, ele) << endl;
}