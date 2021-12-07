//CHAPTER 17 EX 09

#include <iostream>

// Add better comments and double check results

void fun(int *main_local_addr)
{
    int fun_local;
    long stack_growth {main_local_addr-&fun_local};
    uintptr_t numb {(uintptr_t)main_local_addr}; //allows conversion from ptr(hexadecimal) to int
    uintptr_t numb2 {(uintptr_t)&fun_local}; //allows conversion from ptr(hexadecimal) to int
    if ( &fun_local > main_local_addr)
    {
        std::cout<<'('<<numb<<'\n'<<'-'<<'\n'<<numb2<<')'<<'\n'<<"/4=    (4->int size)\n";
        std::cout<<stack_growth<<" » This stack grows upward from its origin.\n";
    }
    else
    {
        std::cout<<'('<<numb<<'\n'<<'-'<<'\n'<<numb2<<')'<<'\n'<<"/4=    (4->int size)\n";
        std::cout<<stack_growth<<" » This stack grows downward from its origin.\n";
    }
}

int main()
{
    double* dp {new double[1000]};
    double* dp2 {new double[1000]};
    long dp3 {dp-dp2};
    uintptr_t numb {(uintptr_t)dp}; //allows conversion from ptr(hexadecimal) to int
    uintptr_t numb2 {(uintptr_t)dp2}; //allows conversion from ptr(hexadecimal) to int
    if (dp3>0)
    {
        std::cout<<'('<<numb<<'\n'<<'-'<<'\n'<<numb2<<')'<<'\n'<<"/8=    (8->double size)\n";
        std::cout<<dp3<<" » This free store grows downward from its origin.\n";
    }
    else if (dp3<0)
    {
        std::cout<<'('<<numb<<'\n'<<'-'<<'\n'<<numb2<<')'<<'\n'<<"/8=    (8->double size)\n";
        std::cout<<dp3<<" » This free store grows upward from its origin.\n";
    }  
    else std::cout<<"unexpected";

    //stack
    int main_local;
    fun(&main_local);
}