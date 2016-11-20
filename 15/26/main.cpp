#include "Quote.h"
#include "Bulk_quote.h"

int main(){
  Quote q1("c++", 5.5);
  //Quote q2(q1);
  Quote q3 = q1;
  //Bulk_quote bq1("c++", 12.5, 5, 0.9);
}
