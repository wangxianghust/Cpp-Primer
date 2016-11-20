#ifndef E13_H
#define E13_H

#include <iostream>
#include <string>

using std::string;

class HasPtr{
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {}
	HasPtr(HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) {}

	HasPtr& operator=(const HasPtr&);

	~HasPtr() { std::cout << "destructor "  << *ps << std::endl; delete ps;};

	int getI() const { return i; }
	string getString() const { return *ps; }
private:
	string* ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr& hp) {
	string* tmp = new string(*hp.ps);
	delete ps;
	ps = tmp;
	i = hp.i;
	return *this;
}

#endif