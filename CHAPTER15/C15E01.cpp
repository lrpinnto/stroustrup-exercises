//CHAPTER 15 EX 01

#include "./sources.h"
#include <stdexcept>

//R: I find the recursive function more elegant, but the iterative I find easier to read.

int fac_iterative(int n)
{
    int r = 1;
    while(n>1){
        r*=n;
        --n;
    }
    return r;
}
int fac(int n) {return n>1 ? n*fac(n-1) : 1; }

int main()
try
{
    for (int i = 0; i <= 20; i++)
    {
        if(fac_iterative(i)!=fac(i)) error("functions don't match on "+ to_string(i));
    }
    cout<<"Everything matches\n";
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
catch(...)
{
    // some more error reporting
    return 2;
}
