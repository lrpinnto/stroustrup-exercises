#include <iostream>

char* strdup(const char * s)
{
    int n {1};
    while(*s){++s;++n;}
    for (int i = 1; i < n; i++)
        --s;
    char* p {new char[n]{*s}};
    for (int i = 1; i < n; i++)
    {
        *++p=*++s;
    }
    for (int i = 1; i < n; i++)
        --p;
    return p;
}

int main()
{
    char s[]{"test test"};
    char* p {strdup(s)};
    int n {0};
    while(p[n] && s[n])
    {
        std::cout<<n<<'|'<<int(p[n])<<'|';
        if(p[n]!=s[n]) {std::cout<<"error";break;}
        n++;
    }
}