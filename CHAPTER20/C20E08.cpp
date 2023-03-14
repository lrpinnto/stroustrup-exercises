//CHAPTER 20 EX 08

//Define a function that counts the number of characters in a Document

#include "./Document.h"

int count_char(Document& d)
{
    int count {0};
    for(auto& x : d)
        if(std::isalnum(x) || std::ispunct(x)) count++;
    return count;
}

int main()
{
    Document d;
    std::cin>>d;
    std::cout<<count_char(d);
}