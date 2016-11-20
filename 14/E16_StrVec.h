#ifndef E16_StrVec_H
#define E16_StrVec_H

#include <string>
using std::string;

#include <memory>
using std::allocator;

#include <utility>
using std::pair;

#include <iostream>
using std::endl;
using std::cout;

#include <initializer_list>
using std::initializer_list;

#include <algorithm>

class StrVec{
    friend bool operator==(const StrVec& lhs, const StrVec& rhs);
    friend bool operator!=(const StrVec& lhs, const StrVec& rhs);
public:
	StrVec(): element(nullptr), first_free(nullptr), cap(nullptr) {};
	StrVec(initializer_list<string> il);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	string* begin() const { return element; }
	string* end() const { return first_free; }
	void push_back(const string& s);
	size_t size() const { return first_free - element; }
	size_t capacity() const { return cap - element; }
	void reserve(size_t n);
	void resize(size_t n);
	void resize(size_t n, const string& s);
private:
	static allocator<string> alloc;
	string* element;
	string* first_free;
	string* cap;
	void free();   // free the all_element in the vector and then free the vector
	void reallocate();     // when the storage is not enough, reallocate the new memory
	void chk_n_alloc();    // check if there is one more storage for the new element
	pair<string*, string*> alloc_n_copy(const string* b, const string* e); // copy from the old vector for construct and assignment
	void alloc_n_move(size_t newcap);
};

allocator<string> StrVec:: alloc = allocator<string>();   // static member must be defined outside the function
bool operator==(const StrVec& lhs, const StrVec& rhs);
bool operator!=(const StrVec& lhs, const StrVec& rhs);
StrVec::StrVec(initializer_list<string> il){
	auto newdata = alloc_n_copy(il.begin(), il.end());
	element = newdata.first;
	first_free = newdata.second;
	cap = first_free;
}

//void StrVec::free(){
//	if(element){
//		for_each(begin(), end(), [](const string& s){ alloc.destroy(&s); } );
//		alloc.deallocate(element, cap-element);
//	}
//}

void StrVec::free()
{
    if (element) {
        for (auto p = first_free; p != element;)
            alloc.destroy(--p);
        alloc.deallocate(element, cap - element);
    }
}


void StrVec::chk_n_alloc(){
	if (first_free == cap) {
		reallocate();
		cout << "memory is not enough!" << endl;
	}
}

void StrVec::alloc_n_move(size_t newcap){  // we can also call the alloc_n_copy function here
	auto newdata = alloc.allocate(newcap);
	auto dest = newdata;
	auto ele = element;
	for(size_t i = 0; i < size(); ++i){
		alloc.construct(dest++, std::move(*ele++));
	}
	free();
	element = newdata;
	first_free = dest;
	cap = element + newcap;
}

void StrVec::reallocate(){
	auto newcapacity = size() ? 2*size() : 1;
	alloc_n_move(newcapacity);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e){
	auto newv = alloc.allocate(e-b);
	auto ret = uninitialized_copy(b, e, newv);
	return {newv, ret};
}

StrVec::StrVec(const StrVec& sv){
	auto new_sv = alloc_n_copy(sv.begin(), sv.end());
	element = new_sv.first;
	first_free = new_sv.second;
	cap = first_free;
}

StrVec& StrVec::operator=(const StrVec& sv){
	auto new_sv = alloc_n_copy(sv.begin(), sv.end());
	free();
	element = new_sv.first;
	first_free = new_sv.second;
	cap = first_free;
	return *this;
}

StrVec::~StrVec(){
	free();
}

void StrVec::push_back(const string& s){
	chk_n_alloc();
	alloc.construct(first_free, s);
	++first_free;
}

void StrVec::reserve(size_t n){
	if(n <= capacity()) return;
	alloc_n_move(n);
}

void StrVec::resize(size_t n){
	resize(n, string());
}

void StrVec::resize(size_t n, const string& s){
	size_t raw_size = size();
	if(n < raw_size){
		while(first_free != element + n){
			alloc.destroy(--first_free);
		}
	} else if(n > raw_size){
		for(size_t j = raw_size; j < n; ++j){
			push_back(s);
		}
	}
}
bool operator==(const StrVec& lhs, const StrVec& rhs){
    return (lhs.size() == rhs.size()) && (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
bool operator!=(const StrVec& lhs, const StrVec& rhs){
    return !(lhs == rhs);
}
#endif
