/*
#include <iostream>

using namespace std;

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	try {
		if (0 == num2) {
			throw 0;
		} else {
			cout << num1/num2 << endl;
		}
	} catch (int i) {
		cout << "divisior is 0 !" << endl;
		cout << "Please give me a new divisior : " << endl;
		cin >> num2;
		cout << num1/num2 << endl;
	}
	return 0;
}
*/

#include <iostream>

using namespace std;

int testDiv(int num1, int num2) {
	int num;
	try {
		if (0 == num2) {
			throw 0;
		} else {
			num = num1/num2;
		}
	} catch (int i) {
		cout << "divisior is 0 !" << endl;
		cout << "Please give me a new divisior : " << endl;
		cin >> num2;
		cout << num1/num2 << endl;
	}
	return num;
}

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	int num;
	try {
		num = testDiv(num1,num2);
		cout << num << endl;
	} catch(int i) {
		num = testDiv(num1,num2);
		cout << num << endl;
	}
}