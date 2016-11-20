#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

// int main(){
// 	ifstream in("../data/book.txt");
// 	istream_iterator<string> str_in(in);
// 	istream_iterator<string> e;

// 	vector<string> v;

// 	while(str_in != e){
// 		v.push_back(*str_in ++);
// 	}

// 	for(auto i : v){
// 		cout << i << "---" << endl;
// 	}

// }

int main(){
	ifstream in("../data/book.txt");
	istream_iterator<string> str_in(in);
	istream_iterator<string> eof;
	vector<string> v;

	copy(str_in, eof, back_inserter(v));
	copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, "\n") );
}