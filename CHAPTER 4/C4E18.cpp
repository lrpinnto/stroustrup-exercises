#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 18

/*ax^2+bx+c=0. Returns x1 and x2.*/
void solve(double a, double b, double c, double *x1, double *x2)
{
    if (b*b-4*a*c<0) //complex roots
    {
        cout<<"This solution has 1 or 2 complex roots. Therefore this is a real solution -> ";
    }
    else
    {
        *x1=((-b-sqrt(b*b-4*a*c))/(2*a));
        *x2=((-b+sqrt(b*b-4*a*c))/(2*a));
    }
}

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double x1;
    double x2;
    
    while (true)
    {
        x1=0;
        x2=0;
        cout<<"Quadratic solver:\n\tEnter the values a b and c for ax^2 + bx + c = 0\n\t";
        cin>>a>>b>>c;
        solve(a,b,c,&x1,&x2);
        cout<<"The solution is "<<x1<<" and "<<x2<<".\n";
    }
    

}