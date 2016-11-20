#include <iostream>
using std::cin;
using std::endl;
using std::cout;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <string>
using std::string;

class IsInRange{
    public:
        IsInRange(int l, int u):lower(l),upper(u) {}
        int getLower() const { return lower; }
        int getUpper() const { return upper; }
        bool operator()(const string& s) const {int _size = s.size();  return _size >= lower && _size <= upper; }
    private:
        int lower;
        int upper;
};

int main(){
    auto uppers = { 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u };
    vector<IsInRange> predicates;
    int low = 1;
    for(auto up : uppers){
        predicates.push_back(IsInRange(low, up));
    }
    map<int, int> count;
    for(auto up : uppers){
        count[up] = 0;
    }
    std::ifstream fin("../data/storyDataFile.txt");
    for(string word; fin >> word;){
        cout << word << "\t";
        for(auto is_in_range : predicates){
            if(is_in_range(word)){
                ++count[is_in_range.getUpper()];
            }
        }
    }

    for(auto pair : count){
        cout << "count in range [1," << pair.first << "] : " << pair.second <<  endl; 
    }
}
