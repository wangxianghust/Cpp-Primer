#ifndef E19_2_H
#define E19_2_H

#include "E19_1.H"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::shared_ptr;
using std::weak_ptr;

class StrBlobPtr{
public:
	StrBlobPtr():curr(0){};
	StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
	string &deref() const;
	StrBlobPtr &incr();
private:
	shared_ptr<vector<string> > check(std::size_t size, const string &) const;
	weak_ptr<vector<string> > wptr;
	size_t curr;
};

shared_ptr<vector<string> > StrBlobPtr::check(size_t i, const std::string &msg) const{
	auto ret = wptr.lock();
	if(!ret){
		throw std::runtime_error("unbound StrBlobPtr!");
	}
	if(i >= ret->size()){
		throw std::out_of_range(msg);
	}
	return ret;
}

string &StrBlobPtr::deref() const{
	auto p = check(curr, "past end !");
	return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr(){
	check(curr, "increasement pass the end");
	++curr;
	return *this;
};

#endif