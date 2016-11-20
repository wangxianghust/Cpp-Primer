#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class numbered{
public:
	static int unique;
	numbered() { ++ unique; }
	numbered(const numbered&) { ++ unique; }
	string get_mysn() const { return to_string(unique); }
private:
	string mysn;
};

void f(const numbered& s) {
	cout << s.get_mysn() << endl;
}

int numbered::unique = 10;

int main(){
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
}