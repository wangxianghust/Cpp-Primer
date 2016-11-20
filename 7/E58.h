#ifndef E58_H
#define E58_H

#include <vector>
using namespace std;

class Example {
public:
	static constexpr double rate = 6.5;
	static const int vecSize = 20;
	static vector<double> vec;
};


constexpr const double Example::rate;
vector<double> Example::vec(vecSize);
#endif