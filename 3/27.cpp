#include <iostream>

using std::endl;

int txt_size() {
	return 12;
}

int main() {
	const unsigned buf_size = 1024;
	int ia[buf_size] = {1,2,3,4,5,6};
	int a[2*5-3]={0};
	// int iaa[txt_size()];
	char st[12] = "fundamental";
	std::cout << ia[2] << endl;
	std::cout << ia[3] << endl;
}