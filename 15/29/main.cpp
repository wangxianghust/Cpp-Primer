#include "Quote.h"
#include "Bulk_quote.h"
#include "Disc_quote.h"

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr;
using std::make_shared;

int main(){
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Bulk_quote>("wang",5,10,0.2));
    basket.push_back(make_shared<Bulk_quote>("w",6,10,0.2));
    basket.push_back(make_shared<Bulk_quote>("wa",1,10,0.2));
    basket.push_back(make_shared<Bulk_quote>("ang",6,10,0.2));
    basket.push_back(make_shared<Bulk_quote>("wang",2,10,0.2));

    for(auto quote : basket){
        cout << quote->isbn() << "-->" << quote->net_price(15) << endl;
    }
}
