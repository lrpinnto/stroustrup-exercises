#include "../stroustrup/std_lib_facilities.h"
/*-----------------------------------------------------------------------------------------------------------Version $9.4.1
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
-----------------------------------------------------------------------------------------------------------Version $9.4.1*/

/*-----------------------------------------------------------------------------------------------------------Version $9.4.2
struct Date
{
    int y,m,d;
    Date(int y, int m, int d);
    void add_day(int n);
};


ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
            << ',' << d.m
            << ',' << d.d << ')';
}

void Date::add_day(int n)
{
    if ((m==2 || m==4 || m==6 || m==9 || m==11) && d+n<=30 && d+n>0)  //Did not implement for different months/years or leap years. Pointless work.
    {
        d+=n;
    }
    else if (d+n<=31 && d+n>0) d+=n;
    else return;
}

Date::Date(int yy, int mm, int dd)          //the book only teaches how to define a constructor a few pages ahead. 
    :y{yy}, m{mm}, d{dd}
{
    if (yy>0 && mm>0 && mm<=12 && dd>0 && dd<=31)
    {
        if (!(((yy % 4 == 0) && (yy % 100 != 0)) || (yy % 400 == 0)) && dd==29) error("leap year"); //check if it's a leap year
    }
    else error("out of bounds date");
}

int main()
{
    Date today {1978,6,25};
    cout<<today;
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout<<tomorrow;
    //Date invalid_test {2004,13,-5};
    //cout<<invalid_test;
}
-----------------------------------------------------------------------------------------------------------Version $9.4.2*/

/*-----------------------------------------------------------------------------------------------------------Version $9.4.3
class Date
{
    int y,m,d;
    public:
        Date(int y, int m, int d);
        void add_day(int n);
        int month() const {return m;}
        int day() const {return d;}
        int year() const {return y;}
};


ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
            << ',' << d.month()
            << ',' << d.day() << ')';
}

void Date::add_day(int n)
{
    if ((m==2 || m==4 || m==6 || m==9 || m==11) && d+n<=30 && d+n>0)  //Did not implement for different months/years or leap years. Pointless work.
    {
        d+=n;
    }
    else if (d+n<=31 && d+n>0) d+=n;
    else return;
}

Date::Date(int yy, int mm, int dd)          //the book only teaches how to define a constructor a few pages ahead. 
    :y{yy}, m{mm}, d{dd}
{
    if (yy>0 && mm>0 && mm<=12 && dd>0 && dd<=31)
    {
        if (!(((yy % 4 == 0) && (yy % 100 != 0)) || (yy % 400 == 0)) && dd==29) error("leap year"); //check if it's a leap year
    }
    else error("out of bounds date");
}

int main()
{
    Date today {1978,6,25};
    cout<<today;
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout<<tomorrow;
    //Date invalid_test {2004,13,-5};
    //cout<<invalid_test;
}
-----------------------------------------------------------------------------------------------------------Version $9.4.3*/

//-----------------------------------------------------------------------------------------------------------Version $9.7.1
enum class Month{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Year {
        static const int min = 1800;
        static const int max = 2200;
    public:
        class Invalid {};
        Year(int x) : y{x} {if (x<min || max <= x) throw Invalid{};}
        int year() {return y;}
    private:
        int y;
};

class Date
{
    int d;
    Month m;
    Year y;
    public:
        Date(Year y, Month m, int d);
        void add_day(int n);
        Month month() const {return m;}
        int day() const {return d;}
        Year year() const {return y;}
};


ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year().year()
            << ',' << int(d.month())
            << ',' << d.day() << ')';
}

void Date::add_day(int n)
{
    if ((int(m)==2 || int(m)==4 || int(m)==6 || int(m)==9 || int(m)==11) && d+n<=30 && d+n>0)  //Did not implement for different months/years or leap years. Pointless work.
    {
        d+=n;
    }
    else if (d+n<=31 && d+n>0) d+=n;
    else return;
}

Date::Date(Year yy, Month mm, int dd)          
    :y{yy}, m{mm}, d{dd}
{
    if (yy.year()>0 && int(mm)>0 && int(mm)<=12 && dd>0 && dd<=31)
    {
        if (!(((yy.year() % 4 == 0) && (yy.year() % 100 != 0)) || (yy.year() % 400 == 0)) && dd==29) error("leap year"); //check if it's a leap year
    }
    else error("out of bounds date");
}

int main()
{
    Date today {Year{1978},Month::jun,25};
    cout<<today;
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout<<tomorrow;
    //Date invalid_test {Year{2004},Month::abc,-5};
    //cout<<invalid_test;
}
//-----------------------------------------------------------------------------------------------------------Version $9.7.1