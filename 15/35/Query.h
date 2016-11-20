#ifndef Query_H
#define Query_H
#include "Query_base.h"
#include "WordQuery.h"
#include <memory>
using std::shared_ptr;

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Query : public Query_base {
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
    public:
        Query(const string&);
        QueryResult eval(const TextQuery&t) const { return q->eval(t); }
        string rep() const { return q->rep(); }
    private:
        Query(shared_ptr<Query_base> query): q(query) {
            cout << "Query::Query(shared_ptr<Query_base> query)" << endl;
        }
        shared_ptr<Query_base> q;
};

inline Query::Query(const string& s) : q(new WordQuery(s)) {
    cout << "Query::Query(const string& s) where s = " + s << endl;
}

ostream& operator<<(ostream &os, const Query &query){
    return os << query.rep();
}

#endif 
