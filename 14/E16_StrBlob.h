#ifndef E16_StrBlob_H
#define E16_StrBlob_H

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

class StrBlob{
    friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator>=(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator<=(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator>(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator<(const StrBlob& lhs, const StrBlob& rhs);
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const {return data->size();}
	bool empty() const { return data->empty(); }
	void push_back(const string &s) const { return data->push_back(s);}
	void pop_back();
    string& operator[](size_t n) { check(n,"out of range"); return data->at(n); }
    const string& operator[](size_t n) const  { check(n,"out of range"); return data->at(n); }

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
    bool operator==(const StrBlob& lhs, const StrBlob& rhs);
    bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
    bool operator>=(const StrBlob& lhs, const StrBlob& rhs);
    bool operator<=(const StrBlob& lhs, const StrBlob& rhs);
    bool operator>(const StrBlob& lhs, const StrBlob& rhs);
    bool operator<(const StrBlob& lhs, const StrBlob& rhs);
    void StrBlob::check(size_type i, const string &msg) const { if(i >= data->size()){ throw out_of_range(msg); } }
    bool operator==(const StrBlob& lhs, const StrBlob& rhs){ return *lhs.data == (*rhs.data); }
    bool operator!=(const StrBlob& lhs, const StrBlob& rhs){ return !(rhs == lhs);
}
bool operator>=(const StrBlob& lhs, const StrBlob& rhs){
    return !(lhs < rhs);
}
bool operator<=(const StrBlob& lhs, const StrBlob& rhs){
    return !(lhs > rhs);
}
bool operator>(const StrBlob& lhs, const StrBlob& rhs){
    return (rhs < lhs);
}
bool operator<(const StrBlob& lhs, const StrBlob& rhs){
    return lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}
#endif
