#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename Sequence>
void print(Sequence const &seq){
	for(const auto &i : seq){
		cout << i << " ";
	}

	cout << endl;
}

int main(){
	vector<int> v ;
	list<int> l;
	for(int i = 0; i < 10; ++i){
		v.push_back(i);
	}

	int count = 0;
	for(auto beg = v.rbegin(); beg != v.crend(); ++beg){
		if(count <=7 && count >= 3){
			l.push_back(*beg);
		}

		++count;
	}

	print(v);
	print(l);
}