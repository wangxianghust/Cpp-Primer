#include "Basket.h"

#include <vector>
using std::vector;
#include <string>
using std::string;

int main(){
    Basket basket;
    basket.add_item(Bulk_quote("wang",2,0,0.2));
    basket.add_item(Bulk_quote("w",6,10,0.2));
    basket.add_item(Bulk_quote("wa",1,10,0.2));
    basket.add_item(Bulk_quote("ang",6,10,0.2));
    basket.add_item(Bulk_quote("wang",2,0,0.2));
    
    basket.total_receipt(cout);
}
