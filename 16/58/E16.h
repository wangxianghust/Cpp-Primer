#ifndef E16_H
#define E16_H

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
using std::uninitialized_copy;

#include <algorithm>
#include <utility>

template<typename T>
class Vec{
public:
	Vec(): element(nullptr), first_free(nullptr), cap(nullptr) {};
	Vec(initializer_list<T> il);
	Vec(const Vec&);
	Vec& operator=(const Vec&);
	~Vec();
	T* begin() const { return element; }
	T* end() const { return first_free; }
	void push_back(const T& s);
	size_t size() const { return first_free - element; }
	size_t capacity() const { return cap - element; }
	void reserve(size_t n);
	void resize(size_t n);
	void resize(size_t n, const T& s);
    template <typename... Args>
    void emplace_back(Args&&... args){
        chk_n_alloc();
        alloc.construct(first_free++, std::forward<Args>(args)...);
    }
private:
	static allocator<T> alloc;
	T* element;
	T* first_free;
	T* cap;
	void free();   // free the all_element in the vector and then free the vector
	void reallocate();     // when the storage is not enough, reallocate the new memory
	void chk_n_alloc();    // check if there is one more storage for the new element
	pair<T*, T*> alloc_n_copy(const T* b, const T* e); // copy from the old vector for construct and assignment
	void alloc_n_move(size_t newcap);
};

template<typename T>
allocator<T> Vec<T>::alloc = allocator<T>();   // static member must be defined outside the function
template<typename T>
Vec<T>::Vec(initializer_list<T> il){
	auto newdata = alloc_n_copy(il.begin(), il.end());
	element = newdata.first;
	first_free = newdata.second;
	cap = first_free;
}

/*
template<typename T>
void Vec<T>::free(){
	if(element){
		for_each(begin(), end(), [](const T& s){ alloc.destroy(&s); } );
		alloc.deallocate(element, cap-element);
	}
}
*/

template<typename T>
void Vec<T>::free()
{
    // if not nullptr
    if(element)
    {
        // destroy it in reverse order.
        for(auto p = first_free; p != element;    )
            alloc.destroy(--p);

        alloc.deallocate(element, capacity());
    }
}


template<typename T>
void Vec<T>::chk_n_alloc(){
	if (first_free == cap) {
		reallocate();
		cout << "memory is not enough!" << endl;
	}
}

template<typename T>
void Vec<T>::alloc_n_move(size_t newcap){  // we can also call the alloc_n_copy function here
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

template<typename T>
void Vec<T>::reallocate(){
	auto newcapacity = size() ? 2*size() : 1;
	alloc_n_move(newcapacity);
}

template<typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e){
	auto newv = alloc.allocate(e-b);
	auto ret = uninitialized_copy(b, e, newv);
	return {newv, ret};
}

template<typename T>
Vec<T>::Vec(const Vec<T>& sv){
	auto new_sv = alloc_n_copy(sv.begin(), sv.end());
	element = new_sv.first;
	first_free = new_sv.second;
	cap = first_free;
}

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& sv){
	auto new_sv = alloc_n_copy(sv.begin(), sv.end());
	free();
	element = new_sv.first;
	first_free = new_sv.second;
	cap = first_free;
	return *this;
}

template<typename T>
Vec<T>::~Vec(){
	free();
}

template<typename T>
void Vec<T>::push_back(const T& s){
	chk_n_alloc();
	alloc.construct(first_free, s);
	++first_free;
}

template<typename T>
void Vec<T>::reserve(size_t n){
	if(n <= capacity()) return;
	alloc_n_move(n);
}

template<typename T>
void Vec<T>::resize(size_t n){
	resize(n, T());
}

template<typename T>
void Vec<T>::resize(size_t n, const T& s){
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
#endif
