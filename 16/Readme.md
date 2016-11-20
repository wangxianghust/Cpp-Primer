#16.9
function template is a blueprint to genarate funcion.
class template is a blueprint to genertate class, and the compiler can not deduce the type directly,
the class user need give the type explicitly.

#16.17
When we want to inform the compiler that a name reprensents a type, we must use the keyword typename, not class.
And there is no difference when we declare the type template pareameter, so there can be interchangable.

#16.32
The process of determining the template arguments from the function argument is known as template argument deduction.
During template argument deduction, the compiler uses types of the argument in the call to find the template arguments
that generate a version of the function that best matches the given call.

#16.33
const conversions:A function parameter that is a reference to a const can be passed a reference to a nonconst object
Array- or function-to-pointer conversions:if the function parameter is not a reference type, then the normal pointer
conversion will be applied to argument of array or function type.

#16.38
make_shared must know the type then it can know what the proper size it should allocate.
when it allocate the memory then return the proper type of shared_ptr to point to it.

#16.40
only the type support the this + 0 can pass the compile. Add return depends on what the + operator return.

#16.54 55
There will have some compile error.

#16.57
The error_msg takes initializer_list as the argument, so only the same or at least convertible elements can stored in it.
In contract, the variadic version provides better flexiblility.

#16.66 67
specialization doesn't effect the function match but overloading will, this is the big difference between two ways.
