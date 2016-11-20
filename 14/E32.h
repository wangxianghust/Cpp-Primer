#ifndef E32_H
#define E32_H

class StrBlobPtr;

class pointer{
    public:
        pointer();
        pointer(StrBlobPtr* p_):p(p_){}
        StrBlobPtr& operator*() const;
        StrBlobPtr* operator->() const;
    private:
        StrBlobPtr* p;
};

StrBlobPtr& pointer::operator*() const {
    return *(this->p);
}

StrBlobPtr* pointer::operator->() const {
    return & this->operator*();
}
#endif 

