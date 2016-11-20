#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<double> v;
	double m;
	while(cin >> m){
		v.push_back(m);
	}
	auto result = accumulate(v.cbegin(), v.cend(), 0);
	cout << result << endl;
}