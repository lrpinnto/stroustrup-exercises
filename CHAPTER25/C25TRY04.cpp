// CHAPTER 25 TRY 04

#include <iostream>

void infinite()
{
    unsigned char max = 160;
    for(signed char i=0; i<max; ++i) 
        std::cout<<int(i)<<'\n';
}

int main()
{
    infinite();
    // signed char is 1 byte, so 8 bits for both negative and positive values. 2^8 = 256, with 256/2 that gives a range of [-128;127].
    // It will never reach max.
    // two complement also makes sure the values follow a pattern 0...127->-128...-1->0...127...
}