#ifndef E31_H
#define E31_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class HasPtr
{
friend void swap(HasPtr&, HasPtr&);
friend bool operator<(const HasPtr&, const HasPtr&);
public:
	HasPtr(const string &s): ps(new string(s)), i(0){}
	HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(0) {}
	// HasPtr& operator=(const HasPtr&);
	HasPtr& operator=(HasPtr);
	string& getPs() const { return *ps; }
	~HasPtr() { delete ps; };
private:
	string *ps;
	int i;
};

// HasPtr& HasPtr::operator=(const HasPtr& hp){
// 	auto newp = new string(*hp.ps);
// 	delete ps;
// 	ps = newp;
// 	i = hp.i;
// 	return *this;
// }

HasPtr& HasPtr::operator=(HasPtr hp){
	swap(*this, hp);
	return *this;
}
/*
	The swap function only exchange the pointer of each other.
	No need for the allocate the memory, so it benifis the efficient
*/
void swap(HasPtr& hpl, HasPtr& hpr){
	using std::swap;
	swap(hpl.ps, hpr.ps);
	swap(hpl.i, hpr.i);
	cout << "calling swap function is done !" << endl;
}

bool operator<(const HasPtr& hpl, const HasPtr& hpr){
	return *hpl.ps < *hpr.ps;
}

#endif