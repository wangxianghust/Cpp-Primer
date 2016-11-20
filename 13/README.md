## Exercise 13.6
The copy-assignment operator is function named 'operator='
This operator is used when assignment occured.
The synthesized copy-assignment operator assign each nonostatic member of the right-hand object to corresponding member of the left-hand object using the copy-assignment operator for the type of that member.
It is synthesized when the class does not define its own.

#Exercise 13.9
As with the copy constructor and the copy-assignment operator, for some classes, the synthesized destructor is defined to disallow objects of the type from being destroyed. Otherwise, the synthesized destructor has an empty function body.
The compiler defines a synthesized destructor for any class that does not define its own destructor.

#ecercise 13.10
When a "StrBlob" object is destroyed, the correspond 'use_count' is decrement.It will be freed if no 'shared_ptr' to that dynamic object.

As for "StrBlobPtr", which is a weak shared pointer, the object dynamically allocated will not be freed.

#exercise 13.24
If 'HasPtr' didn't define the destructor, memory leak will happend. If 'HasPtr' didn't define the copy constructor, when assignment happend, just points copied,the string which 'ps' points haven't been copied.

#exercise 13.25
Copy constructor and copy-assignment operator should dynamically allocate memory for its own, rather than share the object with the right hand operand.

'StrBlob' is using smart pointers which can be managed with synthesized destructor, if an object of 'StrBlob' is out of scope, the destructor for shared_ptr will be called automatically to free the memory dynamically allocated when the 'use_count' goes to 0.

#exercise 13.29
The two swap function in the function body is not matched for the swap(HasPtr&, HasPtr&), it will call the function in the std. So the recursion loop won't happen.

#exercise 13.32
The copy and swap is an elegant way when working with dynamicly allocated memory. In the Message class, nothing is allocated dynamically.Thus using this
idiom makes no sense and will make it more complicated to implement due to the pointers that point back.(may be this is answer for 38)


#exercise 13.33
Because these operator must also update the given 'Folder'. So you know the 'Folder' is just a copy,can not update;
On the other hand, Updating a 'Folder' is a job that the 'Folder' class controls through its 'addMsg' and 'remMsg' members, which will modify the class, so it can not be a const.

#exercise 35
some existing 'Floders' will out of sync with the 'Message' after assignment.
In another word, when we say copy a message, there are two meanings. Firstly, new messsge we called NewM here, get the same contents and folders as the copied one. Secondly, all the correspond folder should update to have this NewM.Obviously, the sythesized copy-control only meet the first requirement.
So,we construct our own copy-contrl to meet the second requirement.
Have an another word, when we allocate resources that reside the outside the class object, it will occurs the problems.

#exercise 38
no necessary, now the copy assignment operator is clear and easy.

#exercise 45
lvalue : reference that can bind to an lvalue
rvalue : reference to an object that is about to be destroyed

we can bind an rvalue reference to expression that require conversion, to literals, or to expression that return an rvalue, but we cannto directly bind an rvalue reference to an lvalue. 