#include "../stroustrup/std_lib_facilities.h"
//-----------------------------------------------------------------------------------------------------------Version $9.4.1
struct Date
{
    int y;
    int m;
    int d;
};

Date today;

void init_day(Date& dd, int y, int m, int d)
{
    if (y>0 && m>0 && m<=12 && d>0 && d<=31)
    {
        if ((((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) && d==29)  //check if it's a leap year
        {
            dd.y=y;
            dd.m=m;
            dd.d=d;
        }
        else if (d==29) return;
        else
        {
            dd.y=y;
            dd.m=m;
            dd.d=d;
        }
    }
    
}

void add_day(Date& dd, int n)
{
    if ((dd.m==2 || dd.m==4 || dd.m==6 || dd.m==9 || dd.m==11) && dd.d+n<=30 && dd.d+n>0)  //Did not implement for different months/years or leap years. Pointless work.
    {
        dd.d+=n;
    }
    else if (dd.d+n<=31 && dd.d+n>0) dd.d+=n;
    else return;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
            << ',' << d.m
            << ',' << d.d << ')';
}

int main()
{
    init_day(today,12,24,2005);  //invalid date test
    cout<<today<<'\n';
    init_day(today,2004,13,-5);  //invalid date test
    cout<<today<<'\n';
    init_day(today,1978,6,25);
    cout<<today<<'\n';
    add_day(today,1);
    cout<<today<<'\n';
}
//-----------------------------------------------------------------------------------------------------------Version $9.4.1