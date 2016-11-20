#include <iostream>

using namespace std;

void print(const int *a) {
	cout << *a << endl;
}

void print(const int *a, const int *b) {
	while(a != b) {
		cout << *(a ++) << "--->";
	}	
	cout << endl;
}

int main() {
	int i = 0;
	int j[2] = {1,5};
	int (&arr)[2] = j;
	// int &arr[2];


	print(&i);
	print(j);
	print(begin(j), end(j));
}