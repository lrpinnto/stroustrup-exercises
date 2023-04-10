// CHAPTER 25 EX 12

// Demonstrate the encryption example

#include "./encryption.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>

#define long int
void send()
{
    const int nchar = 2*sizeof(long);    // 64 bits
    const int kchar = 2*nchar;           // 128 bits

    std::string op;
    std::string key;
    std::string infile;
    std::string outfile;
    std::cout << "please enter inputfile name, output file name, and key:\n";
    std::cin >> infile >> outfile >> key;
    while (key.size()<kchar) key += '0'; // pad key
    std::ifstream inf(infile.c_str());
    std::ofstream outf(outfile.c_str());
    if (!inf || !outf) std::runtime_error("bad file name");

    const unsigned long* k =
        reinterpret_cast<const unsigned long*>(key.data());

    unsigned long outptr[2];
    char inbuf[nchar];
    unsigned long* inptr = reinterpret_cast<unsigned long*>(inbuf); 
    int count = 0;

    while (inf.get(inbuf[count])) {
        outf << std::hex;    // use hexadecimal output
        if (++count == nchar) {
            encipher(inptr,outptr,k);
            // pad with leading zeros:
            outf << std::setw(8) << std::setfill('0') << outptr[0] << ' '
                << std::setw(8) << std::setfill('0') << outptr[1] << ' ';
            count = 0;
        }
    }

    if (count) { // pad
        while(count != nchar) inbuf[count++] = '0'; 
        encipher(inptr,outptr,k);
        outf << outptr[0] << ' ' << outptr[1] << ' ';
    }
}

void receive()
{
    const int nchar = 2*sizeof(long);    // 64 bits
    const int kchar = 2*nchar;           // 128 bits

    std::string op;
    std::string key;
    std::string infile;
    std::string outfile;
    std::cout << "please enter inputfile name, output file name, and key:\n";
    std::cin >> infile >> outfile >> key;
    while (key.size()<kchar) key += '0'; // pad key
    std::ifstream inf(infile.c_str());
    std::ofstream outf(outfile.c_str());
    if (!inf || !outf) std::runtime_error("bad file name");

    const unsigned long* k =
        reinterpret_cast<const unsigned long*>(key.data());

    unsigned long inptr[2];    
    char outbuf[nchar+1];
    outbuf[nchar]=0; // terminator
    unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
    inf.setf(std::ios_base::hex ,std::ios_base::basefield); // use hexadecimal input

    while (inf>>inptr[0]>>inptr[1]) {
        decipher(inptr,outptr,k);
        outf<<outbuf;
    }
}
#undef long

int main()
{
    send();
    receive();
}