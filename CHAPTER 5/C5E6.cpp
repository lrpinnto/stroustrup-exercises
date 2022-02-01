#include "../stroustrup/std_lib_facilities.h"

//CAP 5 EX 06

constexpr double c_abs_0 = -273.15; 
constexpr double f_abs_0 = -459.67;

double ctof(double c)
{
    if(c<c_abs_0) error("Temperature below absolute zero.");
    double f = c * (9.0/5.0) + 32;
    if(f<f_abs_0) error("Temperature below absolute zero.");
    return f;
}

double ftoc(double f)
{
    if(f<f_abs_0) error("Temperature below absolute zero.");
    double c = (f - 32) * (5.0/9.0) ;
    if(c<c_abs_0) error("Temperature below absolute zero.");
    return c;
}

int main()
{
    double a=0;
    cin>>a;
    cout<<ctof(a)<<" "<<ftoc(ctof(a));
}