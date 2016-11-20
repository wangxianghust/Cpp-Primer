#include <iostream>
#include <memory>
#include <string>
#include <string.h>

using std::string;
using std::unique_ptr;
using std::cout;
using std::endl;
using std::cin;

int main(){
	// typedef char charA[5];
	// char *p = new charA;
	cout << "Input the string size first" << endl;
	int size;
	cin >> size;
	char *p = new char[size+1]();
	cin.ignore(3, 'x'); // 3 denotes discard 3 elements, 'x'denotes the charactres before 'x'
						// the function is succesful when any is true
	string s; //dicard the next character
	// cin >> s;
	// strcat(p, s);
	// for(size_t i = 0; i < s.size(); ++i){
	// 	p[i] = s[i];
	// }
	cin.get(p, size +1);
	cout << p << endl;
	delete [] p;
}