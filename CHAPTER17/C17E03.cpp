//CHAPTER 17 EX 03

#include <iostream>

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
    std::cout<<string<<'\n';
    to_lower(string);
    std::cout<<string<<'\n';
    delete[] string;
}