#include "../stroustrup/std_lib_facilities.h"

//CAP 8 EXERCISE 14

//Q: Can we declare a non ref function argument const?
//A: Yes.

//Q: What might that mean?
//A: We pass (as in, copy) the argument into the function without the hability to change the value.

//Q: Why might we want to do that?
//A: If a value is smaller than a reference to itselt (int or
// char) then maybe we don't want to pass a reference but we still want the
// benefits of const?

//Q: Why people don't do that often?
//A: Pass-by const reference seems to be superior in everyway to simply passing a const argument

void f(const int)
{
    cout<<"test";
}

int main()
{
    f(35);
}