#ifndef E27_H
#define E27_H

#include <string>
using std::string;

class HasPtr{
public:
	HasPtr(const string& s):ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
	~HasPtr();
private:
	string *ps;
	int i;
	size_t* use;
};

HasPtr::HasPtr(const HasPtr& hp){
	++(*hp.use);
	i = hp.i;
	ps = hp.ps;
}

HasPtr::~HasPtr(){
	if(--*use == 0){
		delete ps;
		delete use;
	}
}

HasPtr& HasPtr::operator=(const HasPtr& hp){
	++(*hp.use);
	if(--*use == 0){
		delete ps;
		delete use;
	}
	ps = hp.ps;
	i = hp.i;
	use = hp.use;
	return *this;
}

#endif