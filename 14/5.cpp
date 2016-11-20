#include "E5.h"

int main(){
    Book book1(124, "wang", "cpp", "2015");
    Book book2(124, "wang", "cpp", "2015");
    Book book3(124, "wang", "cpp", "2016");
    
    if(book1 == book2){
        cout << book1 << endl;
    }   
    if(book1 == book3){
        cout << book1 << endl;
    }   
}
