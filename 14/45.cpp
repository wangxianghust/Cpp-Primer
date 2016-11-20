#include "E45.h"

int main(){
    Sales_data cp5("C++ Primer 5th", 4, 106.5);
    std::cout << cp5 << std::endl;
    cout << static_cast<string>(cp5) << endl;
    cout << static_cast<double>(cp5) << endl;
    cout <<  (double)cp5 << endl;
}
