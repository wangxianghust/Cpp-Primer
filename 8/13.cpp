#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct  PersonInfo
{
	string name;
	vector<string> phones;
};

bool valid(const string &str) {
	cout << str[0] << endl;
	return isdigit(str[0]);
}

string format(const string & str) {
	return str.substr(0,3) + "-" + str.substr(3,3) + "-" + str.substr(6);
}

int main() {
	ifstream ifs("../data/phonenumbers.txt");
	if(!ifs) {
		cerr << "NO DATA " << endl;
		return -1;
	}

	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while(getline(ifs, line)) {
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while(record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	for (const auto &entry : people) {
		ostringstream formatted, badNums;
		for(const auto &nums : entry.phones)
	}

}