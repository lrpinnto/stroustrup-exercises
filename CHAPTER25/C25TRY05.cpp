// CHAPTER 25 TRY 05

// 128 == 0x00000080 == 00000000000000000000000010000000  4 bytes
// char -> 8 bits, signed bit so 7 usable bits
// that means 10000000 with 1 being the signed bit. With two's-complement that will be -128
// unsigned char has the extra bit meaning the value will now be 128
// 128 == 0x80 == 10000000  1 bytes
// since char is already signed, sc will be -128
// -128 == 0x80 == 10000000  1 bytes (signed)
// 128  -128   128  -128

#include <iostream>

template<typename T>
void print(const T& var)
{
    std::cout<<static_cast<int>(var)<<'\t';
}

int main()
{
    int si = 128;
    char c = si;
    unsigned char uc = si;
    signed char sc = si;
    print(si); print(c); print(uc); print(sc); std::cout<<'\n';
}