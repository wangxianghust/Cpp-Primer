#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"
#include "Query.h"
#include "Query_base.h"

int main(){
   Query q = Query("fiery") & Query("bird") | Query("wind"); 
}
