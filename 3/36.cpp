#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;

bool compare(const int *p_begin, const int *p_last, const int *q_begin, const int *q_last) {
	if (p_last - p_begin != q_last - q_begin) {
		return false;
	} else {
		for (auto i = p_begin, j = q_begin; i != p_last && j != q_last; ++i, ++j) {
			if ( *i != *j) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	int p[] = {1,2,3,4,5};
	int q[] = {1,2,3,4,5};
	
	const int *p_begin = begin(p); 
	const int *q_begin = begin(q);
	const int *p_last = end(p); 
	const int *q_last = end(q);

	bool Flag = compare(p_begin, p_last, q_begin, q_last);
	cout << "Array is equality?   " << Flag << endl;

	std::vector<int> v1{1,2,3}; 
	std::vector<int> v2{1,2,4}; 
	bool vectorFlag = (v1 == v2);
	cout << "Vector is equality?   " << vectorFlag << endl;
}
