#include <iostream>
#include <string>

using namespace std;

void inputInfo(string &s, const string &info) {
	cout << "Please input the " << info << " :" << endl;
	cin >> s;
}

int main() {
	string name, prefix, suffix;
	inputInfo(name, "name");
	inputInfo(prefix, "prefix");
	inputInfo(suffix, "suffix");
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(suffix);
	cout << name << endl;
}