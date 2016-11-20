#include <iostream>
#include <string>
#include <memory>

using std::string;
using std::endl;
using std::cout;

namespace ch16
{
    template<typename T, typename... Args>
    auto make_shared(Args&&... args) -> std::shared_ptr<T>
    {
        return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

struct foo{
    explicit foo(int b) : bar(b) {}
    int bar;
};

int main(){
    auto num = ch16::make_shared<int>(42);
    std::cout << *num << std::endl;

    auto str = ch16::make_shared<string>(10, 's');
    cout << *str << endl;

    auto f = ch16::make_shared<foo>(99);
    cout << f->bar << endl;
}
