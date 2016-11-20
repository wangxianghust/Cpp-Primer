#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct X
{
	X() { cout << "X()" << endl;}
	X(const X&) { cout << "X(const X&)" << endl; }
	X& operator=(const X&) { cout << "X& operator=(const X&)" << endl; }
	~X() { cout << "~X()" << endl; }
};

/*
int main(){
	// X x1;
	X *x1 = new X;
	X x2(*x1);

	vector<X> vec;
	// vec.push_back(*x1);
	// vec.push_back(x2);
	delete x1;
	// delete x2;

	return 0;
}
*/

void f(const X &rx, X x)   // reference is not the copy-assignment
{
    cout << "f start" << endl;
    std::vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    cout << " rx " << endl;
    vec.push_back(x);
    cout << " x " << endl;  // the destrucotor is invoked 3 times.
}

int main()
{
    X *px = new X;
    cout << "new X" << endl;
    f(*px, *px);
    cout << "f end" << endl;
    delete px;
    cout << "delete px" << endl;

    return 0;
}
