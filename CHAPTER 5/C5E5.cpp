#include "../stroustrup/std_lib_facilities.h"

//CAP 5 EX 05

double ctok(double c)
{
    constexpr double abs_0_c = -273.15;
    if (c<abs_0_c) error("ctok(). Input temp is lower than absolute 0.");
    double k = c +273.15;
    return k;
}

double ktoc(double k)
{
    constexpr int abs_0 = 0;
    if (k<abs_0) error("There is no temperature below absolute 0.");
    double c = k - 273.15;
    return c;
}

int main()
{
    double c = 0;
    cin>>c;
    
    double k = ctok(c);
    cout<<k<<'\n';
    c = ktoc(k);
    cout<<c<<'\n';
}