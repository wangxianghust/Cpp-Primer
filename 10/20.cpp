#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<string> v{ "aaa", "ajbewfgg", "s", "joajgiagj", "sdd"};
	size_t sz;
	cin >> sz;

	auto count = count_if(v.begin(), v.end(), 
		[sz](string &a) { return a.size() >= sz; });

	cout << "the length which is bigger than " << sz << " is " << count << endl;
}