#include <iostream>
#include <string.h>

using namespace std;

bool str_subrange(const string &str1, const string &str2) {
	if(str1.size() == str2.size()) {
		return str1 == str2;
	}

	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for(decltype(size) i = 0; i != size; ++i) {
		if(str1[i] != str2[i])
			return false;
	}
}

int main() {
	string s1 = "hebooa";
	string s2 = "hebooas";
	cout << str_subrange(s1, s2) << endl;

}