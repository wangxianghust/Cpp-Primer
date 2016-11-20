#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

#include <algorithm>

class IsEqual{
    public:
        IsEqual(int v):val(v) {}
        bool operator()(int t){ return val == t; }
    private:
        int val;
};

int main(){
    vector<int> v{1,2,2,3,3,4,5,6};
    replace_if(v.begin(), v.end(), IsEqual(3), 100);
    for(size_t i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
}
