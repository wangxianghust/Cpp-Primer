#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print(vector<string> v) {
	for(auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	cout << "------------" << endl;
}

void print1(vector<string>::iterator begin, const vector<string>::iterator end, string s) {
	cout << s << endl;
	for(; begin != end; ++begin){
		cout << *begin << " ";
	}
	cout << endl;
}

int main(){
	vector<string> v{"a", "helloworld", "abc", "avdee", "jiagjaig", "jfioajggj"};
	print(v);

	size_t sz = 5;
	vector<string>::iterator bound;
	bound = partition(v.begin(), v.end(), 
		[sz](const string &a) { return a.size() >= sz; });
	print1(v.begin(), bound, "the size is bigger than 5");
	print1(bound, v.end(), "the size is smaller than 5");

}