#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

int main(){
	ifstream in("./33data.txt");
	istream_iterator<int> int_in(in), eof;

	ofstream out1("./odd.txt");
	ofstream out2("./even.txt");

	ostream_iterator<int> out_iter1(out1, "\n --- \n");
	ostream_iterator<int> out_iter2(out2, "\n --- \n");

	while(int_in != eof){
		if(*int_in & 0x01){
			out_iter1 = *int_in;
		} else {
			out_iter2 = *int_in;
		}
		++int_in;
	}

}