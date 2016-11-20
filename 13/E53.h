#ifndef E53_H
#define E53_H

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

class HasPtr{
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string& s);
	HasPtr(const HasPtr&);
	HasPtr(HasPtr&&) noexcept;
	HasPtr& operator=(const HasPtr &);
    HasPtr& operator=(HasPtr &&) noexcept;
	// HasPtr& operator=(HasPtr);
	~HasPtr();
private:
	string *ps;
	int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs){
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "call swap" << endl;
}

HasPtr::HasPtr(const string& s):ps(new string(s)), i(0) {
	cout << "call constructor" << endl;
}

HasPtr::HasPtr(const HasPtr& hp):ps(new string(*hp.ps)), i(hp.i){
	cout << "call copy constructor" << endl;
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i){
	cout << "call move constructor" << endl;
}

// HasPtr& HasPtr::operator=(HasPtr rhs){
// 	swap(*this,rhs);
// 	return *this;
// }

HasPtr::~HasPtr(){
	cout << "call destructor" << endl;
	delete ps;
}


#endif