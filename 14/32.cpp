#include "E32.h"
#include "E16_StrBlobPtr.h"

int main(){
    StrBlob sb = { "aa", "dfb", "c" };
    StrBlobPtr iter = (sb).begin();
    
    pointer P(&iter);
    cout << P->deref() << endl;
    return 0;
}
