#include <iostream>
#include <vector>

int main()
{
    std::vector<int> iv = {0,1,2,3,4,5,6,7,8,9};
    auto iter = iv.begin(), mid = iv.begin() + iv.size()/2;
    std::cout << "capacity = " << iv.capacity() << std::endl;
    std::cout << "iter's pos: " << iter - iv.begin() << std::endl;  // -12
    std::cout << "mid's pos: " << mid - iv.begin() << std::endl;  // -7
    iv.insert(iter, -1);
    std::cout << "capacity = " << iv.capacity() << std::endl;
    std::cout << "iter's pos: " << iter - iv.begin() << std::endl;  // -12
    std::cout << "mid's pos: " << mid - iv.begin() << std::endl;  // -7

    return 0;
}