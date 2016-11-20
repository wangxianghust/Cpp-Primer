#ifndef OrQuery_H
#define OrQuery_H

#include "BinaryQuery.h"

class OrQuery : public BinaryQuery { 
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& l, const Query& r) : BinaryQuery(l, r, "|") { cout << "AddQuery::AddQuery(const query&, const Query&)" << endl; }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs) {
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif
