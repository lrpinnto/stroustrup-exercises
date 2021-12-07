//Chapter 18 Ex 02

#include <iostream>
#include "./C18.h"

int main()
{
    char* string {new char[14]{'H','e','l','l','o',',','W','W','o','r','l','d','!',0}};
    char* phrase {new char[6]{'W','o','r','l','d',0}};
    const char* spot {findx(string,phrase)};
    if(!spot) {std::cout<<"Nothing has been found\n"; return 0;}
    std::cout<<spot<<' '<<&spot<<'\n';
    for (int i = -7; i < 6; i++)
    {
        std::cout<<spot[i]<<'|';
    }
    std::cout<<int(spot[7])<<'|'<<'\n';
    delete[] string;
    delete[] phrase;
}