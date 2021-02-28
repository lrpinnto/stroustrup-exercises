#include "../stroustrup/std_lib_facilities.h"

//CAP 5 try this

int area(int length, int width)
{
    if (length<=0 || width<=0) error("area() pre-condition");
    int a = length * width;
    if (a<=0) error("area() post condition");
    return a;
    
    
}
int main()
{
    cout<<area(47000,47000);
}