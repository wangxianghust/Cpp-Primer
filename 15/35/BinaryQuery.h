#ifndef BinaryQuery_H
#define BinaryQuery_H

#include "Query.h"
#include "Query_base.h"

class BinaryQuery : public Query_base {
    protected:
        BinaryQuery(const Query& l, const Query& r, string s):
            lhs(l), rhs(r), opSym(s) {}
        string rep() const {
            return "(" + lhs.rep() + " " 
                        + opSym + " " +
                        rhs.rep() + ")";
        }
        //virtual QueryResult eval(const TextQuery) const = 0;
    protected:
        Query lhs,rhs;
        string opSym;
};


#endif 
