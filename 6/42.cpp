#include <iostream>
#include <string.h>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
	return	(ctr > 1) ? word + ending : word;
}

int main() {
	string result = make_plural(1, "ending");
	cout << result << endl;
	result = make_plural(2, "ending");
	cout << result << endl;
	result = make_plural(2, "ending", "again");
	cout << result << endl;
}