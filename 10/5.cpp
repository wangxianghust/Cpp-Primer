#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<string> v1{"a", "as", "abc"};
	vector<string> v2{"a", "as", "d"};
	auto result = equal(v1.cbegin(), v1.cend(), v2.cbegin());
	cout << result << endl;

	vector<const char *> c1{"c", "as", "abc"};
	vector<const char *> c2{"c", "as", "abc", "d"};
	auto result2 = equal(c1.cbegin(), c1.cend(), c2.cbegin());
	cout << result2 << endl;
}