#include <vector>

class NoDefault
{
public:
	// NoDefault( int i ) : base(i) {};
	// // NoDefault() : base(0) {};
	// NoDefault() {}
	NoDefault() = default;
private:
	int base;	
};

class C
{
public:
	C() : def(0) {} ;
private:
	NoDefault def;	
};

int main() {
	// C c;
	// std::vector<C> vec(); 
	NoDefault N;
	std::vector<N> ve();
    return 0;
}