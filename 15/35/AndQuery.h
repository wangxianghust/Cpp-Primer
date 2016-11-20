#ifndef AndQuery_H
#define AndQuery_H

#include "BinaryQuery.h"

class AndQuery : public BinaryQuery { 
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& l, const Query& r) : BinaryQuery(l, r, "&") { cout << "AndQuery::AndQuery(const query&, const Query&)" << endl; }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs) {
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif
