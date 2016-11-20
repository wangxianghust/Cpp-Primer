#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <functional>
#include <vector>
using std::vector;
using std::bind;
using std::modulus;
using std::equal_to;
using std::placeholders::_1;
using std::count_if;

int main(){
    vector<int> v = {2,3,5};
    cout << "Please input the data to divisible: " << endl;
    int div;
    cin >> div;
    int x;
    cin >> x;
    std::modulus<int> mod;
    auto predicate = [=] (int i){int divy = div + x; return 0 == mod(divy, i); };
    bool ret = std::any_of(v.cbegin(), v.cend(), predicate);
    cout << (ret ? "Yes": "No") << endl;
}
