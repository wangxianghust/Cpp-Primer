#include "E12.h"

int main(){
    Blob<int> b{1,2,3,2};
    vector<int> v = {1,2,3};
    Blob<int> bb(v.begin(), v.end());
    cout << bb.size() << " " << bb.back() << endl;
}
