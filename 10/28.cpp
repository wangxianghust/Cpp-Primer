#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>

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
	vector<int> l;
	list<int> l1, l2, l3;
	for(int i = 1; i < 10; ++i){
		l.push_back(i);
	}
	copy(l.cbegin(), l.cend(), inserter(l1, l1.begin() ));
	copy(l.cbegin(), l.cend(), back_inserter(l2 ));
	copy(l.cbegin(), l.cend(), front_inserter(l3 ));

	print(l);
	print(l1, "inserter");
	print(l2, "back");
	print(l3, "front");
}
