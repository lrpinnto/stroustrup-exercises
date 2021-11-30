//CHAPTER 17 EX 05

#include <iostream>

const char* findx(const char* s, const char* x) //needed to set return char* to const
{
    int is {-1}; //-1 so we avoid counting 0
    while(s[is+++1]!=0){} //get array size
    int ix {-1};
    while(x[ix+++1]!=0){} //get array size
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
                else if(j>ix-2)
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