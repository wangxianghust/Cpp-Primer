#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> s = {"1","2","3.5","100","-1"};
	vector<float> result;
	for(auto i : s){
		auto d = stof(i);
		result.push_back(d);
		cout << d << endl;
	}

	float sum = 0;
	for(auto i : result){
		sum += i;
	}
	cout << sum << endl;
}