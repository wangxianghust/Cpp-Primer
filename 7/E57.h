#ifndef E57_H
#define E57_H


#include <string>
using namespace std;

class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static  void rate(double);
private:
	string name;
	double amount;
	static double interestRate;
	static double initRate();
	static constexpr int period = 30;
	double daily_tbl[period];2
};

#endif