#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T>
void print(vector<T> v) {
	for(auto i : v)
		cout << i << endl;
}

template <typename T>
void print(list<T> v) {
	for(auto i : v)
		cout << i << endl;
}

int main() {
	list<int> l(10, 2);

	vector<double> v(l.begin(), l.end());
	print(l);
	cout << "-------" << endl;
	print(v);
	cout << "-------" << endl;
	
}