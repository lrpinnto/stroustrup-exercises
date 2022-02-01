#include "../stroustrup/std_lib_facilities.h"

//CAP 5 EX 04

double ctok(double c)
{
    constexpr double abs_0_c = -273.15;
    if (c<abs_0_c) error("ctok(). Input temp is lower than absolute 0.");
    double k = c +273.15;
    return k;
}

int main()
{
    double c = 0;
    cin>>c;
    
    double k = ctok(c);
    cout<<k<<'\n';
}