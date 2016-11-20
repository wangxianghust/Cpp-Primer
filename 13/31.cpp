#include "E31.h"
#include <algorithm>

#include <vector>
using std::vector;

int main(){
	// vector<HasPtr> v{"a","ab","b","dgj","aa"};
	// vector<string> v{"a","ab","b","dgj","aa"};
    HasPtr s{ "s" }, a{ "a" }, c{ "c" };
    vector<HasPtr> v{s,a,c};
	sort(v.begin(), v.end());
	for(auto &i : v){
		cout << i.getPs() << "---";
		// cout << i << "---";
	}
	cout << endl;
}