#exercise 15.1
A virtual member in a base class expects it's derived class define it's own version;
and the virtual destructor is needed for the base class.

#exercise 15.2
private member: base class itself and friend class can access.
protected member: base class itself, friend class and derived class can access.

#exercise 15.4 
All fault

#exercise 15.8
static type is the type with which a variable is decared or that an expression yields. it can be know at compile time.
dynamic type is the type of object in memory that the variable or expression represents, it may not be know until run time.

#exercise 15.9
The static type of a pointer or reference to a base class, which may differ from it's dynamic type.

#exercise 15.10
the "std::ifstream" derived from the the "std::istream", hence the ifstream is the istream, so it can works.

#exercise 15.12 
Abosolutely, the override is used to tell the compiler this function is derived from the base class, and the final means that
this function can not be overried.

#exercise 15.18
user code may use the derived-to-base conversion when D is derived from B publicly.User code may not use the conversion when
D is inherited from B using either protected or private.

#exercise 15.19
member function and class friends can access the data of D regardeless of the way D inherits from B.
But the class derived from the D can noly access the data of derived-to-base conversion that D inherits from B either public or protected.

#exercise 15.25
Because the Bulk_quote has a 4-parameter constructor, then there will be no default constructor. The derived class of it will have the 
deleted default constructor. In other word, if we use the Bulk_quote::Bulk_quote(), there will be some problems.

#exersice 15.28 & 15.29
when the item of vector is object, the virtual function of derived is not run,which just call its static type.
but in exercise 29, we use the smart point to do this word, it will dynamic call the virtual function.:if expand("%") == ""|browse confirm w|else|confirm w|endif

#exercise 15.32
copied
when smart pointer is copied, the synthesized copy constructor is called, and the use count of this pointer is added to 2;
moved
the original pointer becomes null pointer and the object of the use count of new smart pointer is 1;
copy assigned
the synthesized copy assignment is called. the outcome of this operator is identical with the copy construcor
move assigned
it is just like the move operator
destructor
the synthesized destructor is called. It will call the destructor of 'shared_ptr' which decrement the use count.If the count become zero, the destructor 
will detele the associated recourse.

#exercise 15.33
Managed by it's synthesized version.
