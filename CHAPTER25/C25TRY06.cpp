// CHAPTER 25 TRY 06

#include "./encryption.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
#define long int
    const int nchar = 2*sizeof(long);    // 64 bits
    const int kchar = 2*nchar;           // 128 bits

    std::string key {"bs"};
    std::string infile {"encrypted.txt"};
    while (key.size()<kchar) key += '0'; // pad key
    std::ifstream inf(infile.c_str());
    std::ostringstream oss;
    if (!inf) std::runtime_error("bad file name");

    const unsigned long* k =
        reinterpret_cast<const unsigned long*>(key.data());

    unsigned long inptr[2];    
    char outbuf[nchar+1];
    outbuf[nchar]=0; // terminator
    unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
    inf.setf(std::ios_base::hex ,std::ios_base::basefield); // use hexadecimal input

    while (inf>>inptr[0]>>inptr[1]) {
        decipher(inptr,outptr,k);
        oss<<outbuf;
    }
#undef long

    std::cout<<oss.str();
}