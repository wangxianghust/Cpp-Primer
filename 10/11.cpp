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

bool isShorter(const string &s1, const string &s2){
	return s1.size() < s2.size();
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
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "aed", "turtle"};
	sort(words.begin(), words.end(), isShorter);
	cout << "------" << endl;
	print(words);
	elimDups(words);
	std::vector<string> words2(words);
	sort(words.begin(), words.end(), isShorter);
	print(words);

	stable_sort(words2.begin(), words2.end(), isShorter);
	print(words2);
}