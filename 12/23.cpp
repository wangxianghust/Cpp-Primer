#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;
using std::cout;
using std::endl;

int main(){
	char *p = new char[7];
	string s1("hello");
	string s2("world");
	for(size_t i = 0; i < s1.size(); ++i){
		p[i] = s1[i];
		cout << p[i] << endl;
	}
	for(size_t i = 0; i < s2.size(); ++i){
		p[i] = s2[i];
		cout << p[i] << endl;
	}
	cout << p << endl;
	delete [] p;
	// s1.append(s2);
	// cout << s1 << endl;
}