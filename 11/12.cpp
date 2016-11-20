#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

int main(){
	vector <pair<string, int>> v;
	string word;
	int count = 0;
	while(cin >> word && word != "eof"){
		// v.push_back({word, ++count});
		// v.push_back(make_pair(word, ++count));
		v.push_back(pair<string, int>(word, ++count));
	}

	for(auto &i : v){
		cout << i.first << " " << i.second << endl;
	}
}