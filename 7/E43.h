#ifndef E43_H
#define E43_H

class NoDefault
{
public:
	NoDefault( int i ) : base(i) {};
private:
	int base;	
};

class C
{
public:
	C( NoDefault m) : X(m) {} ;
private:
	NoDefault X;	
};


#endif