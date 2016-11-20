#include <vector>
#include <iostream>

using namespace std;
// class A{

// };

// int main() {
// 	A a,b;
// 	if(a == b) {
// 		cout << "test" << endl;
// 	}
// }


int main() {
	vector<int> v1;
	vector<int> v2;

	int i;
	cout << "input v1 : " << endl;
	while(cin >> i && i !=100) {
		v1.push_back(i);
	}

	cout << "input v2 : " << endl;
	while(cin >> i && i !=100) {
		v2.push_back(i);
	}

	for(auto j : v1) {
		cout << j << " ";
	}
	cout << "----" << endl;
	for(auto j : v2) {
		cout << j << " ";
	}

	if(v1 == v2) {
		cout << " v1 equal v2" << endl;
	} else {
		cout << "no no no " << endl;
	}
}