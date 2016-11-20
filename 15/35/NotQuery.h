#ifndef NotQuery_H
#define NotQuery_H

#include "Query_base.h"
#include "Query.h"

class NotQuery : public Query_base { 
    friend Query operator~(const Query&);
    NotQuery(const Query& q) : query(q) { cout << "NotQuery::NotQuery(const query& q)" << endl; }
    string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

inline Query operator~(const Query& operand) {
    return shared_ptr<Query_base>(new NotQuery(operand));
}

#endif
