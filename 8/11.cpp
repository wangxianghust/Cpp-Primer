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

	for (auto &p : people)
    {
        std::cout << p.name << " ";
        for (auto &s : p.phones)
            std::cout << s << " ";
        std::cout << std::endl;
    }
}