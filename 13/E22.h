#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class HasPtr{
public:
	HasPtr();
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& p) : ps(new string(*p.ps)), i(p.i) {}
	HasPtr& operator=(const HasPtr&);
	~HasPtr() { delete ps; }
private:
	string *ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs){
	auto newp = new string(rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}