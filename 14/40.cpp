#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ShorterString{
    public:
        bool operator()(const string& s, const string& t) const {
            return s.size() < t.size();
        }
};

class SizeComp{
    public:
        SizeComp(int size):size_(size) {}
        bool operator()(const string& s) const {
            return s.size() >= size_;
        }
    private:
        size_t size_;
}; 

class PrintResult{
    public:
        void operator()(const string& s) const {
            cout << s << endl;
        }
};

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

	stable_sort(words.begin(), words.end(), ShorterString());
	print(words);

	auto wc = find_if(words.begin(), words.end(),SizeComp(sz));

	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer " << endl;

	for_each(wc, words.end(), PrintResult());
 
	print(words);
}

int main(){
	size_t sz = 5;
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "aed", "turtle"};
	biggies(words, sz);
}
