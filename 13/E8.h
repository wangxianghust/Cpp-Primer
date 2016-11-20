#ifndef E8_H
#define E8_H

#include <iostream>
#include <string>

using std::string;

class HasPtr{
public:
	HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
	string &getString() const;
	int getI() const;
	HasPtr &operator=(const HasPtr &);
private:
	string *ps;
	int i;
};

string &HasPtr::getString() const{
	return *ps;
}

int HasPtr::getI() const{
	return i;
}

HasPtr& HasPtr::operator=(const HasPtr &hp){
	string* new_ps = new string(*hp.ps);
	delete ps;
	ps = new_ps;
	i = hp.i;
	return *this;
}

#endif