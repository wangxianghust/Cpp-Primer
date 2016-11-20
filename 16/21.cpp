#include <iostream>
using std::ostream;
using std::cerr;
using std::endl;

class DebugDelete{
    public:
        DebugDelete(ostream& s = cerr): os(s) {}
        template<typename T> void operator() (T *p) const {
            os << "deleting unique_ptr" << endl;
            delete p;
        }
    private:
        std::ostream& os;
};

int main(){
    double *p = new double;
    DebugDelete d;
    d(p);
    int *ip = new int;
    DebugDelete()(ip);
}
