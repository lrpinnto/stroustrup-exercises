//Chapter 18 ex 01

#include <iostream>
#include "./C18.h"

int main()
{
    char s[]{"test test"};
    char* p {strdup(s)};
    int n {0};
    while(p[n] && s[n])
    {
        std::cout<<n<<'|'<<int(p[n])<<'|'; // index|char int|
        if(p[n]!=s[n]) {std::cout<<"error";break;}
        n++;
    }
}