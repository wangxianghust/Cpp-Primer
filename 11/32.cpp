#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <typeinfo>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::multimap;
using std::map;
using std::vector;
using std::multiset;

void print(multimap<string, string> works, string info = ""){ 
	cout << "---" << info << "---" << endl;
	for(auto &i : works){
		cout << i.first << " " << i.second << endl;
	}
}

bool compare(string s1, string s2){
	return s1 < s2;
}

int main(){
	std::multimap<string, string> authors;
	authors = {
        { "alan", "DMA" },
        { "pezy", "LeetCode" },
        { "alan", "CLRS" },
        { "wang", "FTP" },
        { "pezy", "CP5" },
        { "wang", "CPP-Concurrency" }
    };

    map<string, multiset<string>> order_authors;
    for(const auto &i : authors){
    	order_authors[i.first].insert(i.second);
    }

    // cout << "type test : " << typeid(order_authors["alan"]).name() << endl;
    for(const auto &author : order_authors){
    	cout << author.first << " has works: ";
    	for(const auto &work : author.second){
    		cout << work << " ";
    	}
    	cout << endl;
    }

}
