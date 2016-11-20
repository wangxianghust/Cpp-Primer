#ifndef E26_String_H
#define E26_String_H

#include <memory>
using std::allocator;

#include <utility>
using std::pair;

#include <algorithm>
using std::for_each;

#include <iostream>
using std::ostream;

class String{
    friend ostream& operator<<(ostream& os, const String& s);
    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);
    friend bool operator>(const String& lhs, const String& rhs);
    friend bool operator<(const String& lhs, const String& rhs);
public:
	String():first(nullptr), last(nullptr) {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();
	char* begin() const { return first; }
	char* end() const { return last; }
	size_t size() const { return last - first; }
	void push_back(const char s);
    const char* c_str() const { return first; }
    char& operator[](size_t n){ return first[n]; };
    const char& operator[](size_t n) const { return first[n]; };
private:
	static allocator<char> alloc;
	char* first;
	char* last;
private:
	void free();
	pair<char*, char*> alloc_n_copy(const char* b, const char* e);
	void alloc_n_move(const char* b, const char* e);
};

allocator<char> String::alloc = allocator<char>();

    ostream& operator<<(ostream& os, const String& s);
    bool operator==(const String& lhs, const String& rhs);
    bool operator!=(const String& lhs, const String& rhs);
    bool operator>(const String& lhs, const String& rhs);
    bool operator<(const String& lhs, const String& rhs);

void String::alloc_n_move(const char* b, const char* e){
	auto newdata = alloc.allocate(e-b);
	auto dest = newdata;
	// for_each(first, last, [dest](char s){ alloc.construct(dest++, s) });
	for( ; first != last; ++first){
		alloc.construct(dest++, *first);
	}
	free();
}

pair<char*, char*> String::alloc_n_copy(const char* b, const char* e){
	auto newdata = alloc.allocate(e-b);
	auto dest = std::uninitialized_copy(b, e, newdata);
	return {newdata, dest};
}

void String::free(){
	if(first){
		for_each(first, last, [this](char& s) { alloc.destroy(&s); });
		alloc.deallocate(first, size());
	}
}

String::String(const char* s){
	auto start = s;
	while(*s != '\0'){
		++s;
	}
	auto ret = alloc_n_copy(start, s);
	first = ret.first;
	last = ret.second;
}

String& String::operator=(const String& s){
	auto ret = alloc_n_copy(s.first, s.last);
	free();
	first = ret.first;
	last = ret.second;
	return *this;
}

String::~String(){
	free();
}

void String::push_back(const char c){
	*last++ = c;
}

ostream& operator<<(ostream& os, const String& s){
    char* c = const_cast<char*>(s.c_str());
    while(*c){
        os << *c++;
    }
    return os;
}

bool operator==(const String& lhs, const String& rhs){
    return (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const String& lhs, const String& rhs){
    return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs){
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String& lhs, const String& rhs){
   return rhs < lhs;
}
#endif
