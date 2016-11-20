#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void check_And_Print(vector<int> v) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
}

void check_And_Print(vector<string> v) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
}

int main() {
	vector<int> v1;
    vector<int > v2(10);
    vector<int> v3(10,42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    vector<string> v8(10);
    vector<string> v9(10, "hi");

    check_And_Print(v1);
    check_And_Print(v2);
    check_And_Print(v3);
    check_And_Print(v4);
    check_And_Print(v5);
    check_And_Print(v6);
    check_And_Print(v7);
    check_And_Print(v8);
    check_And_Print(v9);
}