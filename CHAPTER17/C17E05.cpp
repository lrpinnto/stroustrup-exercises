//CHAPTER 17 EX 05

#include <iostream>

const char* findx(const char* s, const char* x) //needed to set return char* to const
{
    int is {0};
    while(s[is++]!=0){} //get array size
    int ix {0};
    while(x[ix++]!=0){} //get array size
    if(ix>=is) return nullptr; //throw error 

    for (int i = 0; i < is; i++)
    {
        if (s[i]==x[0])
        {
            for (int j = 0; j < ix; j++)
            {
                if (s[i+j]!=x[j])
                {
                    break;
                }
                else
                {
                    return &s[i];
                }
            }
        }
    }
    return nullptr;
}

int main()
{
    char* string {new char[14]{'H','e','l','l','o',',',' ','W','o','r','l','d','!',0}};
    char* phrase {new char[5]{'W','o','r','l','d'}};
    const char* spot {findx(string,phrase)};
    std::cout<<spot<<' '<<&spot<<'\n';
    for (int i = -7; i < 6; i++)
    {
        std::cout<<spot[i]<<'|';
    }
    std::cout<<int(spot[7])<<'|'<<'\n';
    delete[] string;
    delete[] phrase;
}