#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v(10, 2);
	for(auto i : v){
		cout << i << endl;
	}

	fill_n(v.begin(), v.size(), 0);

	for(auto i : v){
		cout << i << endl;
	}
}