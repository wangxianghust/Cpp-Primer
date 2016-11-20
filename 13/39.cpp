#include "E39.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void print(const string& info, StrVec& v){
	cout << "---" << info << "---" << endl;
	for(auto i : v){
		cout << i << endl;
	}
}

int main(){
	StrVec sv;
	for(int i = 0; i < 3; ++i){
		// sv.push_back("hello_" + std::to_string(i));
		sv.push_back("hello");
	}
	StrVec sv1(sv);

	StrVec sv2 = sv;
	// print("copy", sv1);
	// print("assignment", sv2);

	// StrVec sv3;
	// sv3.reserve(50);
	// cout << sv3.capacity() << endl;
	sv1.resize(4);
	print("resize_n", sv1);

	const string s("wang") ;
	sv2.resize(6, s);
	print("resize_n_string", sv2);

	StrVec SV({"he", "hew", "jo"});
	print("initializer_list test", SV);
}