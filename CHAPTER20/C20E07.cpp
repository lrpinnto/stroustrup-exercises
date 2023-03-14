//CHAPTER 20 EX 07

//Find the lexicographical last string in an unsorted vector<string>

#include <string>
#include "./vectoroperators.h"
#include <algorithm>

int main()
{
    std::vector<std::string> m {"A","couple","of","random","strings",". "};
    auto elem {std::max_element(m.begin(),m.end())};
    std::cout<<*elem<<'\n';
    std::vector<std::string> h;
    std::cin>>h; //CTRL+D for interruption
    std::cout<<*(std::max_element(h.begin(),h.end()));
}