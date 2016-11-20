#include <iostream>

using namespace::std;

int main() {
	int score;
	char letter;
	while(cin >> score && score <= 100) {
		if (score >= 90) {
			letter = 'A';
		} else if(score >= 70) {
			letter = 'B';
		} else {
			letter = 'C';
		}
		cout << "socre is " << score << " and letter is " << letter << endl;
	}

}