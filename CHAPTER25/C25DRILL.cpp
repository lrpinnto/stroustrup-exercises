// CHAPTER 25 DRILL

#include <iostream>
#include <bitset>
#include <vector>
#include <iomanip>

int main()
{
    // 1.
    // since int is signed, therefore using two's complement, it will reach 1000 0000 in the last byte which means 0111 1111 but with the minus sign
    int v=1;
    for (int i = 0; i < sizeof(v)*8; ++i)
    {
        std::cout<<v<<' ';
        v<<=1;
    }
    std::cout<<'\n';
    // 2.
    // Similar thing as the last time but since the last bit is not the sign we get 1000 0000 in the last byte
    unsigned int v2=1;
    for (int i = 0; i < sizeof(v2)*8; ++i)
    {
        std::cout<<v2<<' ';
        v2<<=1;
    }
    std::cout<<'\n';
    // 3.
    // each numeral represents 4 bits of memory. Since short unsigned ints have 2 bytes, so 16 bits. It makes sense to represent them in this fashion
    // 4 numerals x 4 bits = 16 bits.
    short unsigned int xa = 0xFFFF;
    short unsigned int xb = 0x0001;
    short unsigned int xc = 0x8000;
    short unsigned int xd = 0x00FF;
    short unsigned int xe = 0xFF00;
    short unsigned int xf = 0x5555;
    short unsigned int xg = 0xAAAA;
    // 4.
    std::vector<short unsigned int> vect {xa,xb,xc,xd,xe,xf,xg};

    for(const auto& i : vect)
    {
        std::bitset<sizeof(short unsigned int)*8> binar {i};
        std::cout<<"0x"<<std::setw(4)<<std::setfill('0')<<std::hex<<i<<": ";
        std::cout<<std::dec<<i<<": ";
        std::cout<<binar<<std::endl;
    }

    // 5. 

    short unsigned int xaa = 0;
    xaa = ~xaa;
    
    short unsigned int xbb = 1;

    short unsigned int xcc = 0;
    xcc=~xcc;
    xcc=xcc>>1;
    xcc=~xcc;

    short unsigned int xdd = 0;
    xdd=~xdd;
    for (size_t i = 0; i < 8; i++)  //using 8 as a literal otherwise I would have to write this code 8 times
        xdd=xdd>>1;

    short unsigned int xee = 0;
    xee=~xee;
    for (size_t i = 0; i < 8; i++) //using 8 as a literal otherwise I would have to write this code 8 times
        xee=xee<<1;
    
    short unsigned int xff = 1;
    for (size_t i = 0; i < sizeof(short unsigned int)*8; i++)
    {   // unsure of a way to do this without using the 2 literal
        if(xff%2!=0) // if odd
            xff=xff<<1;
        else //if even
        {
            xff=xff<<1;
            xff|=1;
        }
    }

    short unsigned int xgg = 1;
    for (size_t i = 0; i < sizeof(short unsigned int)*8; i++)
    {
        if(xgg%2!=0) // if odd
            xgg=xgg<<1;
        else //if even
        {
            xgg=xgg<<1;
            xgg|=1;
        }
    }
    xgg=~xgg;

    std::vector<short unsigned int> vect2 {xaa,xbb,xcc,xdd,xee,xff,xgg};
    if(vect!=vect2) throw std::runtime_error("vectors don't match");

    for(const auto& i : vect2)
    {
        std::bitset<sizeof(short unsigned int)*8> binar {i};
        std::cout<<"0x"<<std::setw(4)<<std::setfill('0')<<std::hex<<i<<": ";
        std::cout<<std::dec<<i<<": ";
        std::cout<<binar<<std::endl;
    }
}