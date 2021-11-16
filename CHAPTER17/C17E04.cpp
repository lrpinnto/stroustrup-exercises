//CHAPTER 17 EX 04

#include <iostream>

void print_array(std::ostream& os, char* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        os<<int(a[i])<<'|';
    }
    os<<'\n';
}

char* strdup(const char* s)
{
    int i {0};
    while(s[i++]!=0){} //get array size
    
    char* string {new char[i]};
    i=-1;
    while(s[++i]!=0){
        string[i]=s[i];
    }
    string[i]=0;
    return string;
}

int main()
{
    char* string {new char[14]{'H','e','l','l','o',',',' ','W','o','r','l','d','!',0}};
    char* p1 {strdup(string)};
    std::cout<<&string<<'\t'; print_array(std::cout,string,14);
    std::cout<<&p1<<'\t'; print_array(std::cout,p1,14);
    delete[] string;
    delete[] p1;
}