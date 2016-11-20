#include <iostream>
template<typename T> int compare(const T&, const T&){
    return 1;
}

int main(){
    compare("bye", "yes");
    compare("bb","heheda");
}
