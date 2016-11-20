#ifndef E17_H
#define E17_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

class Book{
    friend istream& operator>>(istream&, Book&);
    friend ostream& operator<<(ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
    friend bool operator<=(const Book&, const Book&);
    friend bool operator>=(const Book&, const Book&);
    friend bool operator>(const Book&, const Book&);
    friend bool operator<(const Book&, const Book&);

    public:
        Book()=default;
        Book(unsigned no, string name, string author, string pubdate):no_(no), name_(name), author_(author),pubdate_(pubdate) {}
        Book(istream& is){ is >> *this; }
    private:
        unsigned no_;
        string name_;
        string author_;
        string pubdate_;
};

    istream& operator>>(istream&, Book&);
    ostream& operator<<(ostream& os, const Book& book);
    bool operator==(const Book& lhs, const Book& rhs);
    bool operator!=(const Book& lhs, const Book& rhs);
    bool operator<=(const Book&, const Book&);
    bool operator>=(const Book&, const Book&);
    bool operator>(const Book&, const Book&);
    bool operator<(const Book&, const Book&);
    
    istream& operator>>(istream& is, Book& book){
        is >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_;
        if(!is){
            book = Book();
        }
        return is;
    }
    
        
    ostream& operator<<(ostream& os, const Book& book){
        os << book.no_ << " name is : " << book.name_;
        return os;
    }

    
bool operator==(const Book& lhs, const Book& rhs){
    if(lhs.no_ == rhs.no_ ){
        return true;
    } else {
        return false;
    }
}

bool operator!=(const Book& lhs, const Book& rhs){
    return !(lhs == rhs);
}

bool operator<=(const Book& lhs, const Book& rhs){
    return !(lhs > rhs);
}

bool operator>=(const Book& lhs, const Book& rhs){
    return !(lhs < rhs);
}

bool operator>(const Book& lhs, const Book& rhs){
    if(lhs.no_ > rhs.no_){
        return true;
    } else {
        return false;
    }
}

bool operator<(const Book& lhs, const Book& rhs){
    return rhs > lhs;
}

#endif
