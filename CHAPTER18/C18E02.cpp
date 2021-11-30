//Chapter 18 Ex 02

#include <iostream>

const char* findx(const char* s, const char* x)
{
    int is {1};
    while(*s){++s;++is;} //get array size
    for (int i = 1; i < is; i++)
        --s;
    
    int ix {1};
    while(*x){++x;++ix;} //get array size
    for (int i = 1; i < ix; i++)
        --x;
    if(ix>=is) return nullptr; //throw error 

    while(*s)
    {
        if (*s==*x)
        {
            for (int u = 0;x;u++)
            {
                //++x;
                //++s;
                if(*x!=*s)
                {
                    //rewind and break
                    for (int h = 1; h < u; h++)
                    {
                        --s;
                        --x;
                    }
                    break;
                }
                else if(!*++x) //check if next char is 0
                {
                    for (int h = 1; h < u; h++)
                    {
                        --x; // do i also need to rewind s?
                    }
                    return x;
                }
            }
        }
        ++s;
    }
    return nullptr;
}

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