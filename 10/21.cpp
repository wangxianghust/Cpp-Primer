#include <iostream>
#include <string>
#include <vector>
#include <algorthim>

using namespace std;

void func(size_t sz){
	auto f = [&sz]{--sz;
		return sz == 0 ? true : false;};
	auto j = f();
}