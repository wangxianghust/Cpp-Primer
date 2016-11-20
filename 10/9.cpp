#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string> v) {
	for(auto i : v) {
		cout << i << " ";
	}
	cout << endl;
	cout << "------------" << endl;
}
// eliminating duplicates
void elimDups(vector<string> &words){
	print(words);
	sort(words.begin(), words.end());
	print(words);
	auto end_unique = unique(words.begin(), words.end());
	print(words);
	words.erase(end_unique, words.end());
	print(words);
}

int main(){
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	elimDups(words);
}