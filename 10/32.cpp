#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <iterator>

#include "../include/Sales_item.h"

using namespace std;

template<typename Sequence>
void print(vector<Sequence> v, string info = ""){
	cout << "-----" << info << "------";
	for(auto const &i :v){
		cout << i << " ";
	}
	cout << endl;
}

int main(){
	istream_iterator<Sales_item> item_iter(cin), eof;
	vector<Sales_item> v;

	while(item_iter != eof){
		v.push_back(*item_iter++);
	}

	sort(v.begin(), v.end(), compareIsbn);

	for(auto beg = v.cbegin(), end = beg; beg != v.cend(); beg = end){
		// find the first different value with the begin denotes
		end = find_if(beg, v.cend(), [beg](const Sales_item &item){ return item.isbn() != beg->isbn(); });
		// define the += in the header file 
		cout << accumulate(beg, end, Sales_item(beg->isbn()));
	}
}
