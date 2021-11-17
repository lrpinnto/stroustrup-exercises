//CHAPTER 17 EX 09

#include <iostream>

int main()
{
    double* dp {new double[1000]};
    double* dp2 {new double[1000]};
    long dp3 {dp-dp2};
    uintptr_t numb {(uintptr_t)dp}; //allows conversion from ptr(hexadecimal) to int
    uintptr_t numb2 {(uintptr_t)dp2}; //allows conversion from ptr(hexadecimal) to int
    if (dp3>0)
    {
        std::cout<<'('<<numb<<'\n'<<'-'<<'\n'<<numb2<<')'<<'\n'<<"/8=\n";
        std::cout<<dp3<<" » This stack grows upward from its origin.";
    }
    else if (dp3<0)
    {
        std::cout<<'('<<numb<<'\n'<<'-'<<'\n'<<numb2<<')'<<'\n'<<"/8=\n";
        std::cout<<dp3<<" » This stack grows downward from its origin.";
    }  
    else std::cout<<"unexpected";
}