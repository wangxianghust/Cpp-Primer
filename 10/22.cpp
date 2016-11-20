#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz) {
	return s.size() <= sz;
}

int main(){
	vector<string> v{ "aaa", "ajbewfgg", "s", "joajgiagj", "sdd"};
	size_t sz;
	cin >> sz;

	auto count = count_if(v.begin(), v.end(), bind(check_size, _1, sz));

	cout << "the length which is smaller than " << sz << " is " << count << endl;
}