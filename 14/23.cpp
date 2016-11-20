#include "E23.h"

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
		sv.push_back("hello");
	}
	StrVec sv1(sv);

	StrVec sv2 = sv;
	const string s("wang") ;
	sv2.resize(6, s);
    if(sv2 > sv){
        cout << "relation test" << endl;
    }

    if(sv2>=sv) print("print the big", sv2);

    initializer_list<string> il = {"li","wang"};
    sv = il;
    print("initializer_list test", sv);
}
