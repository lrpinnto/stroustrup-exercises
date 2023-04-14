// CHAPTER 25 TRY 03

#include <iostream>
#include <iomanip>
#include <bitset>

int main()
{
    for (unsigned i; std::cin >> i; )
        std::cout << std::dec << i << " == "
                  << std::hex << "0x" << i << " == "
                  << std::bitset<8*sizeof(unsigned)>{i} << '\n';
}