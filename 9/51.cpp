#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &s, const string &delim) {
	vector<string> res;
	string::size_type front = 0;
	string::size_type last = s.find_first_of(delim, front);
	while(last != string::npos){
		if(last > front){
			string tmp = s.substr(front, last-front);
			res.push_back(tmp);
		}
		front = last + 1;
		last = s.find_first_of(delim, front);
	}
	if(last > front){
		res.push_back(s.substr(front, last-front));
	}
	return res;
}

class Time{
public:
	Time(const string s) {auto res = split(s, "/"); year = stoi(res[2]); month = stoi(res[0]); day = stoi(res[1]);};
	void print() {cout << year << "---" << month << "---" << day << endl;}
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
};

int main(){
	Time time("1/5/1995");
	time.print();
	// string s("1/5/1995");
	// vector<string> res;
	// res = split(s, "/");
	// for(auto i: res) {
	// 	cout << i << endl;
	// }	
}

