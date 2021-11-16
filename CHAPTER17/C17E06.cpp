//CHAPTER 17 EX 06

#include <iostream>

int main()
{
    int i {0};
    while(true) {double * di {new double[1000000]};std::cout<<'-'<<++i<<'-';}; 
}

//aprox 441280 * 1000000 * 8 bytes = 3.53 TB (terabytes)
//unsure why it's coming with this impossible amount