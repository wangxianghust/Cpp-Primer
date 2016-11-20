#ifndef Basket_H
#define Basket_H

#include "Quote.h"
#include "Bulk_quote.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <set>
using std::multiset;

#include <iostream>
using std::ostream;

double print_total(ostream &os, const Quote& item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN : " << item.isbn() << " sold: " << n << " total due: " << ret << endl;
    return ret;
}


class Basket{
    public:
       // void add_item(const shared_ptr<Quote>& sales)
       // { items.insert(sales); }
        void add_item(const Quote& sales) { items.insert(shared_ptr<Quote>(sales.clone() )); }
        void add_item(Quote && sales) { items.insert(shared_ptr<Quote>(std::move(sales.clone()))); }
        double total_receipt(ostream&) const;
    private:
        static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
            return lhs->isbn() < rhs->isbn();
        }
        multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

double Basket::total_receipt(ostream& os) const {
    double sum = 0.0;
    for(auto item = items.cbegin(); item != items.cend(); item = items.upper_bound(*item)){
        sum += print_total(os, **item, items.count(*item));
    }
    os << "Total sale : " << sum << endl;
    return sum;
}
#endif
