#ifndef E50_H
#define E50_H

#include <string.h>
#include <iostream>
using namespace std;

class Person;
istream &read(istream &, Person &);

class Person
{
friend istream &read(istream &is, Person &person);
friend ostream &print(ostream &os, const Person &person);
public:
	// construct
	Person() = default;
	Person (const string &s, const string &t) : name(s), address(t) {}
	explicit Person(istream &is){ read(is, *this); }
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