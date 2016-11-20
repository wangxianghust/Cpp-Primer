#include "E34.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
    Select Test;
    cout << Test(1) << endl;
    Select T(1,222,521);
    cout << T(0) << endl;
}
