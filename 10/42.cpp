#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template<typename Sequence>
void print(Sequence const &seq, string info = ""){
	cout << "===" << info << "===" << endl;
	for(const auto &i : seq){
		cout << i << " ";
	}
	cout << endl;
}

int main(){
	list<int> l = {1,1,32,3,2,2,32,4,54,42,21,100,32,100};
	print(l, "original");
	l.sort();
	l.unique();

	print(l, "unique");
}