#ifndef E19_H
#define E19_H

#include <string>
using std::string;

class Employee {
public:
	Employee();  // Ie is just a declaration, if we want to get the id(), we
				// we should wirte it as Employee(){}; then id is defined but 
				// without any value , us Employee():id_(22) {}, we can assign
				// the 22 to the id_, then we can obtain it in the main funcion.
	Employee(const string& name){};
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;

	int id() const { return id_; }
private:
	string name;
	int id_;
	static int identity;
};

#endif