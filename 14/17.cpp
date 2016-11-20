#include "E17.h"

int main(){
    Book book1(124, "wang", "cpp", "20117");
    Book book2(124, "wang", "cpp", "20117");
    Book book3(1294, "wang", "cpp", "2016");
    
    if(book1 == book2){
        cout << book1 << endl;
    }   
    if(book1 <= book3){
        cout << book3 << endl;
    }   
}
