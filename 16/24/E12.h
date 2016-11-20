#ifndef E12_H
#define E12_H

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


template<typename> class BlobPtr;
template<typename> class Blob;

template<typename T> bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T> class Blob{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    public:
        typedef T value_type;
        typedef typename vector<T>::size_type size_type;
        Blob();
        Blob(initializer_list<T> il);
        template<typename It> Blob(It ,It );
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const T &t) { data->push_back(t); }
        void push_back(const T &&t) { data->push_back(std::move(t)); }
        void pop_back();
        T &front() { return data->front(); }
        T &back() { return data->back(); }
        T& operator[] (size_type i);
    private:
        shared_ptr<vector<T>> data;
        void check(size_type i, const string &msg) const;
};

template<typename T> void Blob<T>::check(size_type i, const string &msg) const {
    if (i >= data->size()){
        throw out_of_range(msg);
    }
}

template<typename T> T& Blob<T>::operator[](size_type i){
    check(i, "subscript out of");
    return (*data)[i];
}

template<typename T> Blob<T>::Blob():data(make_shared<vector<T>>()) {}
template<typename T> Blob<T>::Blob(initializer_list<T> il):data(make_shared<vector<T>>(il)) {}
template<typename T> template<typename It> Blob<T>::Blob(It b, It e):
    data(make_shared<vector<T>>(b,e)){}

template <typename T> class BlobPtr{
    public:
        BlobPtr():curr(0) {}
        BlobPtr(Blob<T> &a, size_t sz = 0):
            wptr(a.data), curr(sz) {}
        T& operator*() const { auto p = check(curr, "deference past end"); return (*p)[curr]; }
        BlobPtr &operator++();
        BlobPtr &operator--();
        BlobPtr operator++(int);
        BlobPtr operator--(int);
    private:
        shared_ptr<vector<T>> check(size_t, const string&) const;
        weak_ptr<vector<T>> wptr;
        size_t curr;
};

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int){
    BlobPtr ret = *this;
    ++*this;
    return ret;
}
#endif 
