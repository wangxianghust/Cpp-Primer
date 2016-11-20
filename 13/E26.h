#ifndef E26_H
#define E26_H

#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <initializer_list>
using std::initializer_list;

#include <stdexcept>
using std::out_of_range;
using std::runtime_error;

class StrBlobPtr;
class StrBlob{
friend class StrBlobPtr;
public:
	StrBlobPtr begin() const;
	StrBlobPtr end() const;
	using size_type = vector<string>::size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string& s) { return data->push_back(s); }
	void pop_back();
	string& front();
	string& back();

	//copy constructor
	StrBlob(const StrBlob& sb) : data(make_shared<vector<string>>(*sb.data)) {}
	//assignment constructor
	StrBlob& operator=(const StrBlob& sb);

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string& s) const;
};

class StrBlobPtr{
public:
	using size_type = vector<string>::size_type;
	StrBlobPtr():curr(0) {}
	StrBlobPtr(const StrBlob& sb, size_type sz = 0):wp(sb.data), curr(sz) {}
	const string& deref() const;
	StrBlobPtr& incr();
private:
	weak_ptr<vector<string>> wp;
	size_type curr;
	shared_ptr<vector<string>> check(size_type i, const string& s) const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>> (il)) {}

void StrBlob::check(size_type i, const string& s) const {
	if(i >= data->size() ) throw out_of_range(s);
}

string& StrBlob::front(){
	check(0, "front on the empty vector !");
	return data->front();
}

string& StrBlob::back(){
	check(0, "back on the empty vector !");
	return data->back();	
}

StrBlob& StrBlob::operator=(const StrBlob& sb){
	data = make_shared<vector<string>>(*sb.data);
	return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_type i, const string& s) const {
	auto ret = wp.lock();
	if(!ret){
		throw runtime_error("unbound StrBlobPtr!");
	} else {
		if(i >= ret->size()) throw out_of_range(s);
	}
	return ret;
}

const string& StrBlobPtr::deref() const {
	auto p = check(curr, "The curr is out of range !");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
	check(curr, "The curr is out of range !");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin() const{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() const{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

#endif