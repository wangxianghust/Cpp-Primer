#include "Quote.h"
#include "Bulk_quote.h"

int main(){
  Quote q1("c++", 5.5);
  Bulk_quote q2("computer", 105);
  q2.getInfo();
  //Bulk_quote bq1("c++", 12.5, 5, 0.9);
}
