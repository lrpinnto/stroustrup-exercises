//Chapter 18 Ex 05 && 6 && 7

#include <iostream>

std::string cat_dot_string(const std::string& s1, const std::string& s2, const std::string& separator)
{
    return s1+separator+s2;
}

char* cat_dot(const char* s1, const char* s2, const char* separator)
{
    int is1 {0};
    while(*s1){++s1;++is1;} //get array size
    for (int i = 0; i < is1; i++)
        --s1;
    int is2 {0};
    while(*s2){++s2;++is2;} //get array size
    for (int i = 0; i < is2; i++)
        --s2;
    int iseparator {0};
    while(*separator){++separator;++iseparator;} //get array size
    for (int i = 0; i < iseparator; i++)
        --separator;
    char* p {new char[is1+is2+iseparator+1]};
    while(*s1){ 
        *p=*s1;
        ++p;
        ++s1;
    }
    while(*separator){ 
        *p=*separator;
        ++p;
        ++separator;
    }
    while(*s2){ 
        *p=*s2;
        ++p;
        ++s2;
    }
    *p=0;
    for (int i = 1; i < is1+is2+iseparator+1; i++)
        --p;
    return p;
}

int main()
{
    std::cout<<cat_dot_string("test1","test2","@");
    std::cout<<'\n';
    char* p {cat_dot("test1","test2","@")};
    std::cout<<p;
    delete[] p;
    std::cout<<'\n';
}