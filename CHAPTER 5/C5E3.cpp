#include "/home/pinto/stroustrup/std_lib_facilities.h"

//CAP 5 EX 03

double ctok(double c)
{
    int k = c +273.15;
    return k;
}

int main()
{
    constexpr double abs_0_c = -273.15;

    double c = 0;
    cin>>c;
    if (c<abs_0_c) error("Input temp is lower than absolute 0.");
    
    double k = ctok(c);
    cout<<k<<'\n';
}