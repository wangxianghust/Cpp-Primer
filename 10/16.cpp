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

void elimDups(vector<string> &words){
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

string make_plural(size_t size, const string &word, const string &s){
	auto words = size > 1 ? word + s : word;
	return words;
}

void biggies(vector<string> &words, size_t sz) {
	print(words);
	elimDups(words);
	print(words);

	stable_sort(words.begin(), words.end(), 
		[](const string &s1, const string &s2) { return s1.size() < s2.size(); });
	print(words);

	auto wc = find_if(words.begin(), words.end(),
		[sz] (const string &s) { return s.size() >= sz; });

	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer " << endl;

	for_each(wc, words.end(), 
		[](const string &s) { cout << s << endl; });
 
	print(words);
}

int main(){
	size_t sz = 5;
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "aed", "turtle"};
	biggies(words, sz);
}