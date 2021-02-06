#include "/home/pinto/stroustrup/std_lib_facilities.h"

//CAP 5 EX 02

double ctok(double c)
{
    int k = c +273.15;
    return k;
}

int main()
{
    double c = 0;
    cin>>c;
    double k = ctok(c);
    cout<<k<<'\n';
}