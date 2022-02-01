#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 8 & 9

 //1 2 4 8 16 32 64 128 254 512 1024 2048 4096 8192
 //2^x

//amout = 2^x <> log(amount)=log(2^x)<> log(amount)= xlog(2)
int rice (int amount)
{
    if (amount<=0) return 0; //logarithm is indef
    if (amount>=2147483647) 
    {
        cin.clear();
        return -1 ;//overflow
    }
    
    double x = log(amount)/log(2);
    round(x);
    
    return x+1;
}

int main()
{
    while (true)
    {
        int rice_amount;
        cout<<"Please enter the amount of rice you want to get: ";
        cin>>rice_amount;
        cout<<"You need at least "<<rice(rice_amount)<<" squares to get "<<rice_amount<<" amount of rice.\n";
    }
}