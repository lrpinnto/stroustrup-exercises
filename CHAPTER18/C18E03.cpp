//Chapter 18 Ex 03

#include <iostream>

int strcmp(const char* s1, const char* s2)
{
    while(*s1 && *s2)
    {
        if(*s1<*s2)
            return -1;
        else if(*s1>*s2)
            return 1;
        ++s1;
        ++s2;
    }
    if(*s1<*s2)
        return -1;
    else if(*s1>*s2)
        return 1;
    else return 0;
}

int main()
{
    char* string {new char[14]{'H','e','l','l','o',',','W','W','o','r','l','d','!',0}};
    char* phrase {new char[6]{'W','o','r','l','d',0}};
    int spot {strcmp(string,phrase)};
    std::cout<<spot;
    delete[] string;
    delete[] phrase;
}