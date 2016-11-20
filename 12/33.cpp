#include "E33.h"

void runQuries(ifstream& infile){
	TextQuery tq(infile);
	while(true){
		string word;
		cout << "Please input the word to search : " << endl;
		if( !(cin >> word) || word == "q" ) break;
		QueryResult result = tq.query(word);
		print(cout, result);
		///// test /////
		cout << *(result.begin())<< "--->" << *(--result.end())<< endl;
		cout << result.get_file() << "--->" << *(result.end())<< endl;
	}
}

int main(){
	ifstream infile("../data/storyDataFile.txt");
	runQuries(infile);
}