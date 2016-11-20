#ifndef E12_H
#define E12_H

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
    friend bool operator>(const Book& book1, const Book& book2);
    friend bool operator<(const Book& book1, const Book& book2);
    friend Book operator+(const Book&, const Book&);
    public:
        Book()=default;
        Book(unsigned no, string name, string author, string pubdate, int num):no_(no), name_(name), author_(author),pubdate_(pubdate), num_(num) {}
        Book(istream& is){ is >> *this; }
        Book& operator+=(const Book& book);
    private:
        unsigned no_;
        string name_;
        string author_;
        string pubdate_;
        int num_;
};

    istream& operator>>(istream&, Book&);
    ostream& operator<<(ostream& os, const Book& book);
    bool operator==(const Book& lhs, const Book& rhs);
    bool operator!=(const Book& lhs, const Book& rhs);
    bool operator>(const Book& book1, const Book& book2);
    bool operator<(const Book& book1, const Book& book2);
    Book operator+(const Book&, const Book&);
    
    istream& operator>>(istream& is, Book& book){
        is >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_ >> book.num_;
        if(!is){
            book = Book();
        }
        return is;
    }
    
        
    ostream& operator<<(ostream& os, const Book& book){
        os << book.no_ << " name is : " << book.name_ << "number is: " << book.num_;
        return os;
    }

    
bool operator==(const Book& lhs, const Book& rhs){
    if(lhs.no_ == rhs.no_){
        return true;
    } else {
        return false;
    }
}

bool operator!=(const Book& lhs, const Book& rhs){
    return !(lhs == rhs);
}


bool operator>(const Book& book1, const Book& book2){
    return book1.no_ > book2.no_;
}


bool operator<(const Book& book1, const Book& book2){
    return book2 > book1;
}

Book operator+(const Book& book1, const Book& book2){
    Book ret = book1;
    ret += book2;
    return ret;
}


Book& Book::operator+=(const Book& book){
    if(book == *this){
        num_ += book.num_;
    } 
    return *this;
}

#endif
