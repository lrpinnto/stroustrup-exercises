//CHAPTER 17 EX 08

#include <iostream>

std::string cinarray(std::istream& is)
{
    std::string string;
    for (char c ; is.get(c); )
    {
        if(c=='!') 
        {
            break;
        }
        else
        {
            string+=c;
        }
    }
    return string;
}

int main()
{
    std::cout<<"input a string of characters and end it with !.\n";
    std::string array {cinarray(std::cin)};
    std::cout<<array;
}