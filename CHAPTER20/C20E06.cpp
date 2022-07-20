//CHAPTER 20 EX 06 

#include "./Document.h"

Text_iterator find_replace_txt(Text_iterator first, Text_iterator last, const std::string& s, const std::string& replacement)
{
    auto p {find_txt(first,last,s)};
    if(p==last) return last;
    Text_iterator first_elem {p};
    for (char c : replacement)
    {
        if(p==last) break;
        *p=c;
        ++p;
    }
    return first_elem;
}

std::string replace_text1()
{
    std::string s;
    std::cout<<"Please input the text you would like to have replaced\n";
    std::getline(std::cin,s);
    return s;
}

std::string replace_text2()
{
    std::cout<<"What would you like to replace it with? (keep in mind the text ";
    std::cout<<"will extend beyond the word until the end of the documents where clipping will occur)\n";
    std::string replacement;
    std::getline(std::cin,replacement);
    return replacement;
}

int main()
{
    std::string s {replace_text1()};
    std::string replacement {replace_text2()};
    std::cout<<"Test input. Please write something. When done, press ctrl+d\n"; //Couldnt find a way to clear the std::cin state from EOF
    std::cout<<"################################################\n";
    Document d;
    std::cin>>d;
    std::cout<<"################################################\n";
    std::cout<<"COPY OF YOUR DOC\n";
    std::cout<<"################################################\n";
    print(d);
    std::cout<<"################################################\n";
    std::cout<<"WITH TEXT REPLACED\n";
    std::cout<<"################################################\n";
    auto p {find_replace_txt(d.begin(),d.end(),s,replacement)};
    if(p==d.end())
        std::cout<<"not found\n";
    else
        print(d);
    std::cout<<"\n################################################\n";
}