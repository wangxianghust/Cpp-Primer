#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename Sequence>
void print(Sequence const & seq, string info = ""){
	cout << "-----" << info << "-----" << endl;
	for(const auto &i : seq){
		cout << i << " ";
	}
	cout << endl;
}

int main(){
	vector<int> v;
	for(int i = 0; i < 10; ++i){
		v.push_back(i);
	}

	print(v, "the original");

	for(auto iter = v.crbegin(); iter != v.crend(); ++iter){
		cout << *iter << endl;
	}

	print("the ordinal order");

	for(auto j = v.end()-1; j != v.cbegin(); --j){
		cout << *j << endl;
	}
	cout << *v.begin() << endl;

	v.push_back(0);
	v.push_back(100);

	list<int> l;
	copy(v.cbegin(), v.cend(), back_inserter(l));

	auto iFind = find(l.crbegin(), l.crend(), 0);
	cout << distance(l.crend(),iFind) << endl;
	cout << *iFind << endl;
}