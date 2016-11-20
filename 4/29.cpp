#include <iostream>
#include <vector>

using namespace std;

int main() {
	int x[10];
	int *p = x;
	cout << sizeof(x) << endl;
	cout << sizeof(*x) << endl;
	cout << sizeof(p) << endl;
	cout << sizeof(*p) << endl;

	std::vector<int> v={1,2,5,6,1};
	std::vector<int>::size_type cnt = v.size();
	cout << "-----" << endl;
	cout << cnt << endl;
	for(std::vector<int>::size_type ix=0; ix != v.size(); ++ix, cnt--){
		v[ix] = cnt;
	}

	for ( auto i : v) {
		cout << i << endl;
	}
}