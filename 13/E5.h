#ifndef E5_H
#define E5_H

#include <iostream>
#include <string>

using std::string;

class HasPtr{
public:
	HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
	string &getString() const;
	int getI() const;
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

#endif