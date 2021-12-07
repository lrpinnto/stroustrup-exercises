//Chapter 18 Ex 03

#include <iostream>
#include "./C18.h"

int main()
{
    char* string {new char[14]{'H','e','l','l','o',',','W','W','o','r','l','d','!',0}};
    char* phrase {new char[6]{'W','o','r','l','d',0}};
    int spot {strcmp(string,phrase)};
    std::cout<<spot;
    delete[] string;
    delete[] phrase;
}