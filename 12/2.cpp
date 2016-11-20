#include "E2.h"

int main(){
	// initializer_list<string> il{"hello","test","again"};
	// StrBlob sb(il);
	StrBlob sb{ "hello", "world", "Mooophy" };
	const StrBlob csb{ "hello", "world", "pezy" };

	// cout << csb.front() << " " << csb.back() << endl;
	// cout << "-----" << endl;
	// std::cout << sb.size() << std::endl;
	cout << sb.front() << " " << sb.back() << endl;

	csb.push_back("hello test ---");
	cout << csb.back() << endl;
}