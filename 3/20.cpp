#include <iostream>
#include <vector>
#include <string.h>

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
	for (unsigned int i = 0; i < v.size() -1; ++i) {
		int sum = v[i] + v[i+1];
		cout <<  sum << endl;	
	}

//unsigned int i = 0, j=0;

	for (unsigned int i = 0, j=v.size()-1 ; i<=j; ++i, --j) {
		int sum=0;
		if( i < j) {
			sum = v[i] + v[j];
		} else {
			sum = v[i];
		}
		cout <<  sum << endl;	
	}
		
	
}