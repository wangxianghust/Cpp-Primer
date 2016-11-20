#include "E32.h"
#include <iostream>

using std::cin;
using std::endl;
using std::cout;

void runQueries(ifstream& infile){
	TextQuery qt(infile);  // mark:the stream that is infile, will destroyed once
						// so, should put the order here, or in the scope of while,
						// I should create the stream every loop, which is costly.
	while(true){
	// auto &in = infile;
	// ifstream in(file);
	// cout << in;
		string word;
		cout << "Please input the word to query : " << endl;
		if( !(cin >> word) || word == "q" ) break;
		QueryResult result = qt.query(word);
		print(cout, result);
		// word.clear();
	}
}

int main(){
	string file("../data/storyDataFile.txt");
	ifstream infile(file);
	runQueries(infile);
}