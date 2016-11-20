#ifndef E19_1_H
#define E19_1_H

#include <initializer_list>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <exception>
#include "E19_2.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;
using std::out_of_range;

class StrBlobPtr;

class StrBlob{
	friend class StrBlobPtr;
	// StrBlobPtr begin() { return StrBlobPtr(*this);}
	// StrBlobPtr end(){
	// 	auto ret = StrBlobPtr(*this, data->size());
	// 	return ret;
	// }
	StrBlobPtr begin();
	StrBlobPtr end();
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const {return data->size();}
	bool empty() const { return data->empty(); }
	// void push_back(const string &s) { return data->push_back(s);}
	void push_back(const string &s) const { return data->push_back(s);}
	void pop_back();

	// string &front() const { cout << "const front "; return data->front(); }
	// string &back() const { cout << "const back "; return data->back(); }

	string &front() { cout << "nonconst front "; return data->front(); }
	string &back() { cout << "nonconst back "; return data->back(); }

	const string &front() const {
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

#endif
