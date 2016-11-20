#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "../include/E26.h"

using namespace std;

void print(vector<string> v) {
	for(auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	cout << "------------" << endl;
}

bool inline compare(const Sales_data &data1, const Sales_data &data2) {
	return data1.isbn().size() < data2.isbn().size();
}

int main(){
	std::vector<Sales_data> v;
	Sales_data s1("aa");
	Sales_data s2("aga");
	Sales_data s3("aa");
	Sales_data s4("axxxx");
	Sales_data s5("ag");

	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);

	sort(v.begin(), v.end(), compare);
	for(auto i : v) {
		cout << i.isbn() << endl;
	}
}