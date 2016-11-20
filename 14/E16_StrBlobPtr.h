#ifndef E16_StrBlobPtr_H
#define E16_StrBlobPtr_H

#include <initializer_list>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;
using std::out_of_range;
using std::weak_ptr;

class StrBlobPtr;

class StrBlob{
	friend class StrBlobPtr;
    public:
	StrBlobPtr begin(); 
	StrBlobPtr end();
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const {return data->size();}
	bool empty() const { return data->empty(); }
	void push_back(const string &s) const { return data->push_back(s);}
	void pop_back();

	string &front() { return data->front(); }
	string &back() { return data->back(); }

	//*** Add for the exercise 32 ***//
	string &child(size_type index) { return *( (*data).begin() + index ); }

	const string& front() const {
		check(0, "front on empty StrBlob!");
		return data->front();
	}


	const string& back() const {
		check(0, "bacm on empty StrBlob!");
		return data->back();
	}

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
	if(i >= data->size()){
		throw out_of_range(msg);
	}
};


class StrBlobPtr{
    friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
public:
	StrBlobPtr():curr(0){};
	StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
	string &deref() const;
	StrBlobPtr &incr();
    string& operator[](size_t n) {auto p = check(n,"out of range"); return (*p)[n]; }
    const string& operator[](size_t n) const  { auto p = check(curr,"out of range"); return (*p)[n]; }
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr  operator++(int);
    StrBlobPtr  operator--(int);
    StrBlobPtr& operator+=(size_t n);
    StrBlobPtr& operator-=(size_t n);
    StrBlobPtr  operator+ (size_t n) const;
    StrBlobPtr  operator- (size_t n) const;
    string& operator*() const { auto p = check(curr,"deference out of range"); return (*p)[curr];} 
    string* operator->() const { return & this->operator*(); }
    
private:
	shared_ptr<vector<string> > check(std::size_t size, const string &) const;
	weak_ptr<vector<string> > wptr;
	size_t curr;
};

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);

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
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    return lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    return !(lhs == rhs);
}
bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    return rhs < lhs;
}
bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    return lhs.curr < rhs.curr;
}
bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    return !(lhs < rhs);
}
bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    return !(lhs > rhs);
}

StrBlobPtr& StrBlobPtr::operator++(){
    check(curr, "incresement past end of the ptr");
    ++curr;
    return *this;
}
StrBlobPtr& StrBlobPtr::operator--(){
    --curr;
    check(curr, "decresement past begin of ptr");
    return *this;
}
StrBlobPtr  StrBlobPtr::operator++(int){
    auto ret = *this;
    ++*this;
    return ret;
}
StrBlobPtr  StrBlobPtr::operator--(int){
    auto ret = *this;
    --*this;
    return ret;
}
StrBlobPtr& StrBlobPtr::operator+=(size_t n){
    curr += n;
    check(curr, "+= past end of range");
    return *this;
}
StrBlobPtr& StrBlobPtr::operator-=(size_t n){
    curr -= n;
    check(curr, "-n past end of range");
    return *this;
}
StrBlobPtr  StrBlobPtr::operator+ (size_t n) const {
    auto ret = *this;
    ret += n;
    return ret;
}
StrBlobPtr  StrBlobPtr::operator- (size_t n) const {
    auto ret = *this;
    ret -= n;
    return ret;
}


StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
	return StrBlobPtr(*this, data->size());
}
#endif
