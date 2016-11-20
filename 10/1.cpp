#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int c;
	cout << "Input the vector" << endl;
	while(cin >> c && c != 0){
		v.push_back(c);
	}

	cout << "Input the number" << endl;
	int m;
	cin >> m;
	auto result = count(v.cbegin(), v.cend(), m);
	cout << "The " << m << " appears " << result << " times" << endl;
}