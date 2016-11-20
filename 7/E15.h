#ifndef E15_H
#define E15_H

#include <string.h>
#include <iostream>
using namespace std;

struct Person;
istream &read(istream &, Person &);

struct Person
{
	// construct
	Person() = default;
	Person (const string &s, const string &t) : name(s), address(t) {}
	Person(istream &is){ read(is, *this); }

	string name;
	string address;
	string getName() const {return name;}	
	string getAddress() const {return address;}	
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