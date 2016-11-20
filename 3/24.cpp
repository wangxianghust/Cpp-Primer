#include <iostream>
#include <vector>
#include <string.h>
#include <typeinfo>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int main()
{
	vector<string> ivec;
	// ivec[0] = 42;
	ivec.push_back("start");
	std::cout << ivec[0] << endl;

	std::vector<int> v{1,2,3,4,5,6,7,8,9};
	/*
	auto it = v.begin();
	cout << typeid(it).name() << endl;
	cout << *it << endl;

	auto it3 = it + 1;
	cout << typeid(it3).name() << endl;
	cout << *it3 << endl;


	auto it2 = v.end();
	cout << typeid(it2-1).name() << endl;
	cout << *(it2-1) << endl; 
	
	cout << "test  " << ((it+9)==it2) << endl;

	*/
	for (auto it = v.begin(); (it+1) != v.end(); ++it) {
		int sum = *it + *(++it);
		cout <<  sum << endl;	
	}


	for (auto it = v.begin(),it2 = v.end()- 1 ; it<=it2; ++it, --it2) {
		int sum=0;
		if( it < it2) {
			sum = *it + *it2;
		} else {
			sum = *it;
		}
		cout <<  sum << endl;	
	}

}