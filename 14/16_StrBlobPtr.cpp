#include "E16_StrBlobPtr.h"


int main(){
    StrBlob sb = { "aa", "dfb", "c" };
    StrBlobPtr iter = (sb).begin();
    for(; iter != sb.end() ; ++iter){
        cout << iter.deref() << endl;
    }

    StrBlob sb1 = {"a", "ab", "abc", "abcd"};
    StrBlobPtr iter1 = sb1.begin();
    iter1 += 2;
    cout << "subcript test___" << endl;
    cout << iter1.deref() << endl;
    cout << "derefence test and -> test" << endl;
    cout << *iter1 << endl;
    cout << iter1->size() << endl; 
    return 0;
}
