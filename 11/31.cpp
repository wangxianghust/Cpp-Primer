#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::multimap;

void print(multimap<string, string> works, string info){ 
	cout << "---" << info << "---" << endl;
	for(auto &i : works){
		cout << i.first << " " << i.second << endl;
	}
}

/*
int main(){
	multimap<string, string> works;
	for(string author, title; cout << " Please input : ", cin >> author >> title && author != "eof"; ){
		works.insert( {author, title} );
	}

	print(works);
	cout << "Enter the element to delete " << endl;
	string element;
	cin >> element;
	// auto ret = works.find(element);
	// if(ret != works.end()) works.erase(ret);
	for(auto pos = works.equal_range(element); pos.first != pos.second; ++pos.first){
		cout << " test " << pos.first->second;
		works.erase(pos.first);
	}
	cout << "----" << endl;
	print(works);
}

*/

int main(){
	std::multimap<string, string> authors{
        { "alan", "DMA" },
        { "pezy", "LeetCode" },
        { "alan", "CLRS" },
        { "wang", "FTP" },
        { "pezy", "CP5" },
        { "wang", "CPP-Concurrency" }
    };

    print(authors, "original");
    // want to delete an element that author is [Alan], work is [112].
    string author = "pezy";
    string work = "CP5";

    auto found = authors.find(author);
    int count = authors.count(author);

    while(count){
    	if((*found).second == work){
	    	authors.erase(found);
    	}
    	--count;
    	++found;
    }

    print(authors, "processed");
}