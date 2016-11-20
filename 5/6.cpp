#include <iostream>

using namespace::std;

int main() {
	int score;
	char letter;
	while(cin >> score && score <= 100) {
		letter = score >= 90 ? 'A' :
				 score >= 70 ? 'B' :
				 'C';
		cout << "socre is " << score << " and letter is " << letter << endl;
	}

}