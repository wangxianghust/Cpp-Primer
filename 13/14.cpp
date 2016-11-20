#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

// class numbered{
// public:
// 	numbered(): mysn(to_string(rand())) {}
// 	string get_mysn() { return mysn; }
// private:
// 	string mysn;
// };

class numbered{
public:
	static int unique;
	numbered() { ++ unique; }
	string get_mysn() { return to_string(unique); }
private:
	string mysn;
};

void f(numbered s){
	cout << s.get_mysn() << endl;
}

int numbered::unique = 10;
/*
string randNum(unsigned int seed) {
	srand(seed);
	auto num = rand();
	return std::to_string(num);
}
*/

int main(){
	// for(auto i = 1; i < 10; ++i){
	// 	cout << randNum(i) << endl;
	// }
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
}