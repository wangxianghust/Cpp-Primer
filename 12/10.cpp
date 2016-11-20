#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;


void process(shared_ptr<int> ptr){
	cout << "Inside the process function: " << ptr.use_count() << endl;

}

int main(){
	shared_ptr<int> p(new int(42));
	process(shared_ptr<int>(p));

	cout << p.use_count() << endl;
	auto q =  p;
	cout << p.use_count() << endl;
	cout << "the int p now points to is: " << *p << endl;
}