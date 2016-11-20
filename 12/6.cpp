#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> *fun1(){
	return new vector<int>;
}

void fun2(vector<int> *vi){
	int i;
	while(cin >> i && i != 0){
		vi->push_back(i);
	}
}

void fun3(vector<int> *vi){
	for(auto begin = (*vi).begin(); begin != (*vi).end(); ++begin){
		cout << *begin << endl;
	}
}

int main(){
	auto vi = fun1();
	fun2(vi);
	fun3(vi);
	delete vi;
}