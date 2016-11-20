#include <iostream>
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;
using std::cout;
using std::endl;

int main(){
	unique_ptr<string> p1(new string("test"));
	// unique_ptr<string> p2(p1);
	unique_ptr<string> p3;
	p3 = p1;
}