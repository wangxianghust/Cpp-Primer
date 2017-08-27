#include <iostream>
#include <bitset>
#include <string>

using namespace std;

template<class T>
void print(T val, string info=""){
    cout << val << " " << info << endl;
}

int main(){
    bitset<32> vec(1U << 3);
    print(vec);
    vec.flip();
    print(vec);
    print(vec.count(), "count");
    print(vec.test(3), "test pos3 ");
}
