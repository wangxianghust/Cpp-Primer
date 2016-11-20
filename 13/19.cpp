// No, cause there really is no sensible meaning to copy the employee.

#include "E19.h"
#include <iostream>

int main(){
	Employee m;
	Employee n("wang");

	std::cout << m.id() << std::endl;
	std::cout << n.id() << std::endl;
}