#ifndef Query_base_H
#define Query_base_H

#include "E27.h"
#include <string>
using std::string;

class Query_base{
    friend class Query;
    protected:
        using line_no = TextQuery::line_no;
        virtual ~Query_base() = default;
    private:
        virtual QueryResult eval(const TextQuery&) const = 0;
        virtual string rep() const = 0;
};


#endif
