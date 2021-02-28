#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 5

void operation (double a , double b, char op)
{
    switch (op)
    {
    case '+':
        cout<<"The sum of "<<a<<" and "<<b<<" is "<<a+b<<".\n";
        break;
    case '-':
        cout<<"The subtraction of "<<a<<" and "<<b<<" is "<<a-b<<".\n";
        break;
    case '/':
        cout<<"The division of "<<a<<" and "<<b<<" is "<<a/b<<".\n";
        break;
    case '*':
        cout<<"The product of "<<a<<" and "<<b<<" is "<<a*b<<".\n";
        break;
    
    default:
        cout<<"Please input a valid operation!";
        break;
    }
}

int main ()
{
    double a = 0;
    double b = 0;
    char op = 0;
    while (true)
    {
        cout<<"Please enter the desired operation:\n\t";
        cin>>a>>op>>b;
        operation(a,b,op);
    }
}