#include <iostream>

void print_array(std::ostream& os, char* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        os<<a[i];
    }
    os<<'\n';
}

void to_lower(char* s)
{
    int dif {97-65}; //ascii diference between A and a
    int i {-1};
    while(s[++i]!=0)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            s[i]+=dif;
        }
    }
}

int main()
{
    char* string {new char[14]{'H','e','l','l','o',',',' ','W','o','r','l','d','!',0}};
    print_array(std::cout,string,14);
    to_lower(string);
    print_array(std::cout,string,14);
    delete[] string;
}