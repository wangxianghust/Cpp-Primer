template <typename T,typename U, typename V> void f1(T,U,V);
template <typename T1> T1 f2(T1&);
inline template <typename T> T foo(T, unsigned int*);   // this is a warning that inline will be ignored.

int main() {
    return 0;
}
