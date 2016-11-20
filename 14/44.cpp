#include <functional>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <exception>
using std::runtime_error;

#include <string>
using std::string;
#include <map>
using std::map;

int add(int i, int j){
    return i+j;
}

struct divide{
    int operator()(int i, int j){
        try{
            int ret = i/j;
            return ret;
        } catch(std::exception err){
            cout << err.what() << "\n try again !" << endl;
            int i,j;
            cin >> i >> j;
            return operator()(i,j);
        }
    }
};

auto mod = [](int i, int j){ return i % j; };

int main(){
    map<string,std::function<int(int,int)>> binops = {
        {"+", add},
        {"/", divide()},
        {"%", mod},
        {"-", std::minus<int>()},
        {"*", [](int i, int j){ return i*j; } }
    }; 
   cout << binops["+"](5,10) << endl;
   cout << binops["/"](10,3) << endl; 
   cout << binops["-"](10,3) << endl; 
   cout << binops["*"](10,3) << endl; 
   cout << binops["%"](10,3) << endl; 
}
