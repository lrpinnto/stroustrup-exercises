#include "../stroustrup/std_lib_facilities.h"

//CAP 6 EX 10

int factorial(int number)
{
    if (number<0 || number>12) error("Out of bounds");  //Cannot exceed INT_MAX
    if (number==0)
    {
        return 1;
    }
    int result = number;
    for (int i = number; i > 1; i--)
    {
        number-=1;
        result*=number;
    }
    return result;    
}

double permutation(int a, int b)
{
    if(a-b<0) error("Out of bounds");
    return factorial(a)/factorial(a-b);
}

double combination(int a, int b)
{
    return permutation(a,b)/factorial(b);
}

int main()
try {
    char choice = 'f';
    int a=0;
    int b = 0;
    while (true)
    {
        cout<<"Type a, b and your function separated by spaces:\t\tf - factorial ; p - permutations ; c - combinations\n";
        cin>>a>>b>>choice;
        if(!cin) error("Wrong input");
        switch (toupper(choice))
        {
        case 'F':
            cout<<factorial(a)<<'\n';
            break;
        case 'C':
            cout<<combination(a,b)<<'\n';
            break;
        case 'P':
            cout<<permutation(a,b)<<'\n';
            break;
        default:
            error("No such function exists");
            break;
        }
    }
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}