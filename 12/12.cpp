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
	int *p = new int();
	shared_ptr<int> sp = make_shared<int>();
	process(sp);
	process(new int());
}