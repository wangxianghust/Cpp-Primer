#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz){
	return s.size()  sz;
}

int main(){
	vector<int> v = {1,2,3,4,5,6,3,8,5};
	string s("hello");
	auto result = find_if(v.begin(), v.end(), bind(check_size, s, _1));
	// for(auto i = result; i != v.end(); ++i){
	// 	count << *i << endl;
	// }
	cout << *result << endl;
}
