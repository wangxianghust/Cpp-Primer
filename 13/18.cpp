#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Employee{
public:
	Employee():id(identifier++) { }
	Employee(string _name):name(_name),id(identifier++) { }
	int getId() const { return id; }
	string getName() const { return name; }
private:
	string name;
	int id;
	static int identifier;
};

int Employee::identifier = 0;

int main(){
	Employee m;
	Employee n("wang");
	cout << m.getId() << "---> " << m.getName() << endl;
	cout << n.getId() << "---> " << n.getName() << endl;
}

// Question
// The difference between the private static member and
// the public static member.