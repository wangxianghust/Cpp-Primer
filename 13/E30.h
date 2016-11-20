#ifndef E30_H
#define E30_H

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

class HasPtr{
friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string s):ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& hp):ps(new string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr&);
	~HasPtr();
private:
	string *ps;
	int i;
};

HasPtr& HasPtr::operator=(const HasPtr& hp){
	auto newp = new string(hp.ps);
	delete ps;
	ps = newp;
	i = hp.i;
}

void sawp(HasPtr& hpl, HasPtr& hpr){
	using std::swap;
	swap(hpl.ps, hpr.ps);
	swap(hpl.i, hpr.i);

	cout << " calling swap(HasPtr&, HasPtr&) is done !"
}


#endif