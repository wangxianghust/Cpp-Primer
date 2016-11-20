#ifndef E22_H
#define E22_H

#include <string.h>
#include <iostream>
using namespace std;

struct Person;
istream &read(istream &, Person &);

struct Person
{
friend istream &read(istream &is, Person &person);
friend ostream &print(ostream &os, const Person &person);
public:	
	// construct
	Person() = default;
	Person (const string &s, const string &t) : name(s), address(t) {}
	Person(istream &is){ read(is, *this); }
	string getName() const {return name;}	
	string getAddress() const {return address;}	
private:
	string name;
	string address;
};

istream &read(istream &is, Person &person) {
	is >> person.name >> person.address;
	return is;
}

ostream &print(ostream &os, const Person &person) {
	os << person.name << " " << person.address;
	return os;
}

#endif