#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
	istream_iterator<int> in(cin);
	istream_iterator<int> eof;
	vector<int> v(in, eof);

	sort(v.begin(), v.end());
	ostream_iterator<int> os(cout, " < ");
	unique_copy(v.begin(), v.end(), os);
}