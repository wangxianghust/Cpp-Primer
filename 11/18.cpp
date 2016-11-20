#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using Map = map<string, size_t>;

int main(){
	Map word_count = { {"ab", 1}, {"adw", 2} };
	map<string, size_t>::const_iterator map_it = word_count.cbegin();
	// auto map_it = word_count.cbegin();
	while(map_it != word_count.cend()){
		cout << map_it->first << " " << map_it->second << endl;
		++map_it;
	}
}