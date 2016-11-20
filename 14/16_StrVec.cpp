#include "E16_StrVec.h"

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
    if(sv2 == sv){
        cout << "equal test" << endl;
    }

    cout << (sv2==sv) << endl;
    print("sv2", sv2);
    cout << (sv1==sv) << endl;

}
