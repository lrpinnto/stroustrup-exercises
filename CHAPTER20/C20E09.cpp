//CHAPTER 20 EX 09 & 10

//Ex 09
//Define a program that counts the number of words in a Document. Provide 2 versions: one that defines word as "a whitespace-separated sequence of characters"
//and one that defines word as "a sequence of consecutive alphabetic charaters". For example, with the former definition, alpha.numeric and as12b are both
//single words, whereas with the second definiton they aer both 2 words.
//Ex 10
//Define a version of the word-counting program where the user can specify the set of whitespace characters.

#include "./Document.h"
#include <sstream>
#include <cctype>
#include <algorithm>

int count_words(Document& d)
{
    int count {0};
    std::string s;
    std::stringstream ss;
    for(auto& p : d) ss<<p;
    while(ss>>s) count++; //strings are defined as being sequences of letters separeted by whitespace or \n
    return count;
}

int count_alpha(Document& d)
{
    int count {0};
    std::string s;
    std::stringstream ss;
    for(auto& p : d)
    {
        if(!isalpha(p)) ss<<' ';
        else ss<<p;
    } 
    while(ss>>s) count++;
    return count;
}

int count_def(Document& d, std::vector<char>& w_chars) //using STL notions
{                                                     //using some knowledge from chapter 21
    //essentially, replaces every occurence of w_chars with ' '
    std::replace_if(d.begin(),d.end(),
                    [w_chars](char c){return (w_chars.end()!=std::find(w_chars.begin(), w_chars.end(), c));},
                    ' '
    );
    int count {0};
    std::string s;
    std::stringstream ss;
    for(auto& p : d) ss<<p;
    while(ss>>s) count++;
    return count;
}

int main()
{
    Document d;
    std::cout<<"Input a string to test functions. Ctrl+D to stop input\n";
    std::cin>>d;
    std::cout<<count_words(d)<<'\n';
    std::cout<<count_alpha(d)<<'\n';
    std::vector<char> some_chars {'.',',',':','1'};
    std::cout<<count_def(d,some_chars)<<'\n';
}