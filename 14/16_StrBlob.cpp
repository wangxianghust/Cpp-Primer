#include "E16_StrBlob.h"

int main(){
	// initializer_list<string> il{"hello","test","again"};
	// StrBlob sb(il);
	StrBlob sb{ "xhello", "world", "Mooophy" };
	const StrBlob csb{ "hello", "world", "pezy" };

	// cout << csb.front() << " " << csb.back() << endl;
	// cout << "-----" << endl;
	// std::cout << sb.size() << std::endl;
	cout << sb.front() << " " << sb.back() << endl;

	csb.push_back("hello test ---");
	cout << csb.back() << endl;

	StrBlob sb2{ "xhello", "world", "Mooophy" };
    cout << (sb == sb2) << " equal test" << endl;
	StrBlob sb3{ "hello", "world", "Mooophy","wan" };
    if( sb3 >= sb ) cout << " > test " << endl;
    cout << "subscirpt operter test" << endl;
    for(size_t i = 0; i < sb3.size(); ++i){
        cout << sb3[i] << endl;
    }
}
