#include "E22.h"

int main(){
    Sales_data data;
    cin >> data;
    Sales_data data1;
    cin >> data1;

    auto sum = data + data1;
    cout << sum;

    string isbn = "Test";
    Sales_data test = isbn;
    cout << test << endl;
}
