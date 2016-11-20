#ifndef E34_H
#define E34_H

class Select{
    public:
        Select(int a=0, int b=1, int c=2):first(a),second(b),third(c) {}
        int operator()(int s=0){ first = s;return first ? second : third;}
    private:
        int first;
        int second;
        int third;
};

#endif 
