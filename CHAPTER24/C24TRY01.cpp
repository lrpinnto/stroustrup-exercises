// CHAPTER 24 TRY 01

// Run example with 10 instead of 333

#include <iostream>
#include <iomanip>

int main()
{
    float x {1.0/333};
    float sum {0};
    for (int i = 0; i < 333; i++) sum+=x;
    std::cout<<std::setprecision(15)<<sum<<'\n';

    std::cout.unsetf(std::ios::fixed);
    std::cout.unsetf(std::ios::floatfield);
    float x2 {1.0/10};
    std::cout<<x2<<'\n';
    float sum2 {0};
    for (int i = 0; i < 10; i++) sum2+=x2;
    std::cout<<std::setprecision(15)<<sum2<<'\n';
}
/*
0.999999463558197
0.100000001490116
1.00000011920929
*/