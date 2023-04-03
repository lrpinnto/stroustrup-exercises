// CHAPTER 24 TRY 02

// test f() and g() with a variety of values

#include <iostream>
#include <limits>

void f(int i, double fpd)
{
    char c = i; // yes: chars really are very small integers
    short s = i; // beware: an int may not fit in a short int
    i=i+1; // what if i was the largest int?
    std::cout<<"i: "<<i<<'\n';
    long lg = i*i; // beware: a long may not be any larger than an int
    float fps=fpd; // beware: a large double may not fit in a float
    std::cout<<"fps: "<<fps<<'\n';
    i=fpd; // truncates: eg., 5.7 -> 5
    fps=i; // you can lose precision (for very large int values)
    std::cout<<"fps: "<<fps<<'\n';

    std::cout<<"c: "<<c<<" s: "<<s<<" i: "<<i<<" lg: "<<lg<<'\n';
}

void g()
{
    char ch=0;
    for (int i = 0; i < 500; ++i)
        std::cout<<int(ch++)<<'\t';
}

int main()
{
    g();
    // char is 8 bits (1 byte)
    // 2^8 = 256
    // 256 / 2 (because signed) = 128
    // 0111 1111 -> 127 in binary
    // 1000 0000 -> -128 in two's complement

    std::cout<<"\n\n";
    // quite troublesome results
    f(std::numeric_limits<int>::max(), std::numeric_limits<double>::max());
    std::cout<<'\n';
    f(std::numeric_limits<int>::min(), std::numeric_limits<double>::min());
}