#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
#include <initializer_list>
using std::initializer_list;


class Foo{
public:
	Foo(){};
	Foo(initializer_list<int> il):data(il) {}
	Foo sorted() const &;
	Foo sorted() &&;
	vector<int> get() { return data; }	
private:
	vector<int> data;
};

/*
Foo Foo::sorted() const & {
	cout << "&" << endl;
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	return ret;
}
*/

Foo Foo::sorted() const & {
	cout << "const &" << endl;
	Foo ret(*this);
	return ret.sorted();
}

Foo Foo::sorted() && {
	sort(data.begin(), data.end());
	cout << "&&" << endl;
	return *this;
}


int main(){
	/*
	auto d = Foo({1,8,4,2,0}).sorted();
	for(auto i : d.get()){
		cout << i << endl;
	}
	*/
	/*
	Foo d({1,8,4,2,0});
	auto dd = d.sorted();
	for(auto i : dd.get()){
		cout << i << endl;
	}
	*/

	Foo().sorted();
	Foo f;
	f.sorted();
}