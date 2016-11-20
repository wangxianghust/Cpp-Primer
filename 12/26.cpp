#include <iostream>
#include <memory>
#include <string> 

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::allocator;

int main(){
	int n;
	cout << "input the allocate size : " << endl;
	cin >> n;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	string *q = p;
	while(cin >> s && q != p + n){
		alloc.construct(q++, s);
	}

	while(q != p){
		cout << *(--q) << endl;
		alloc.destroy(q);
	}

	alloc.deallocate(p, n);
}