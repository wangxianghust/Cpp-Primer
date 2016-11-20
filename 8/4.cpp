#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string ifileName = "./README.md";
	ifstream input(ifileName);
	vector<string> v;
	if( input ) {
		string s;
		while(getline(input, s)) {
			v.push_back(s);
		}
	}
	for(auto i : v) {
		cout << i << endl;
	}
}
