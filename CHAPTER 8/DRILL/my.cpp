#include "./my.h"
#include "../../stroustrup/std_lib_facilities.h"

int foo;

void print_foo()
{
    cout<<foo;
}

void print(int i)
{
    cout<<i<<'\n';
}



void swap_v(int a,int b)
{
    int temp; temp = a, a=b; b=temp;
}

void swap_r(int& a,int& b)
{
    int temp; temp = a, a=b; b=temp;
}
//didn't compile due to the nature of the arguments. It's impossible to re-define a constant expression as seen by a=b and b=temp. Both constants
/*
void swap_vr(const int& a, const int& b)
{
    int temp; temp = a, a=b; b=temp;
}*/
