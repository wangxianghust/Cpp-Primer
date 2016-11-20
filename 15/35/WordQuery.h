#ifndef WordQuery_H
#define WordQuery_H

#include "Query.h"
#include "Query_base.h"

class WordQuery : public Query_base {
    friend class Query;
    private:
    WordQuery(const string& s) : query_word(s) {
        cout << "WordQuery::WordQuery(const string& s) where s = " + s << endl;
    }
    string rep() const override;
    QueryResult eval(const TextQuery& t) const override;
    string query_word;
};

string WordQuery::rep() const {
    return query_word;
}

QueryResult WordQuery::eval(const TextQuery& t) const {
    return t.query(query_word);
}
#endif 
