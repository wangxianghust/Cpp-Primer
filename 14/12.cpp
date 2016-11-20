#include "E12.h"

int main(){
    Book book1(124, "wang", "cpp", "2015", 125);
    Book book2(124, "wang", "cpp", "2015", 13);
    Book book3(121, "wang", "cpp", "2016", 15);
    
    if(book1 == book2){
        cout << book1 << endl;
    }   
    if(book1 > book3){
        cout << book3 + book1 << endl;
    }   
}
