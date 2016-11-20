#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;


using Type = std::vector<int>;

shared_ptr<Type> fun1(){
	return make_shared<Type>();
}

void fun2(shared_ptr<Type> p) {
	int i;
	while(cin >> i && i != 0){
		p -> push_back(i);
	}
}

void fun3(shared_ptr<Type> p) {
	for(auto i : *p){
		cout << i << "--->";
	}
}

int main(){
	shared_ptr<Type> p = fun1();
	fun2(p);
	fun3(p);
}

