#include "E27.h"

void runQueries(ifstream &infile){
	TextQuery tq(infile);
	while(true){
		cout << "Enter the word to serach : " << endl;
		string s;
		if(!(cin >> s) || s == "q")break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(){
	string file("../data/storyDataFile.txt");
	ifstream input(file);
	runQueries(input);
}