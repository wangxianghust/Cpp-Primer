#include <string>
using std::string;
#include <utility>
using std::pair;

class Shape{
    public:
        using coordinate =  pair<int, int>;
        Shape() = default;
        Shape(string& no):name(no) {}
        virtual int area() const = 0;
        virtual ~Shape();
    private:
        string name;
};

class Rect : public Shape{
    public:
       Rect() = default;
       Rect(string& no, coordinate& a_, coordinate& b_, coordinate& c_, coordinate& d_):
           Shape(no), a(a_), b(b_), c(c_), d(d_) {}
       ~Rect() = default;
    protected:
        coordinate a;
        coordinate b;
        coordinate c;
        coordinate d;
};

class Squre : public Rect{
    public:
       Squre();
       Squre(string& no, coordinate& a_, coordinate& b_, coordinate& c_, coordinate& d_):
           Rect(no, a_, b_, c_, d_) {}
       ~Squre() = default;
};

int main(){
    return 0;
}
