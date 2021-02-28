#include "../stroustrup/std_lib_facilities.h"

//CAP 5 EX 11

int main()
try{
    int a=0;
    int b=1;
    int n=0 ;
    int sum=1;

    cin>>n;
    if (!cin) error("weird input. Maybe too high?");
    if (n<=0) error("Input has to be positive");
    
    cout<<sum<<" ";
    for (int i = 2; i <= n; i++)
    {
        if(a+b<sum) 
        {
            cerr<<"Max fibonaci number "<<sum<<"\n";

            error("Overflow");
        }
        sum=a+b; 
        
        a=b;
        b=sum;
        cout<<sum<<" ";
    }
    
}
catch(exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    return 2;
}
