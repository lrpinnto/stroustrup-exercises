//Chapter 18 EX 04

#include "./C18.h"
#include <iostream>

//not getting the output I was expecting.
//compiler manages to handle zero-less char arrays quite well (g++)

int main()
{
    char* string {new char[13]{'H','e','l','l','o',',','W','W','o','r','l','d','!'}}; //"fake" C style strings
    char* phrase {new char[5]{'W','o','r','l','d'}};
    char stringarr[13]{'H','e','l','l','o',',','W','W','o','r','l','d','!'}; //"fake" C style strings
    char phrasearr[5]{'W','o','r','l','d'};

    std::cout<<strdup(string)<<'\n'; //works with no issues ---
    std::cout<<findx(string,phrase)<<'\n';
    std::cout<<strcmp(string,phrase)<<'\n';//---

    std::cout<<strdup(phrasearr)<<'\n'; //stacks phrasearr before stringarr so phrasearr becomes "WorldHello,WWorld!".
    std::cout<<findx(stringarr,phrasearr)<<'\n'; //stacks phrasearr before stringarr so phrasearr becomes "WorldHello,WWorld!". returns null
    std::cout.clear(); //null ptr messes with cout??
    int test {strcmp(stringarr,phrasearr)};
    std::cout<<strcmp(stringarr,phrasearr)<<test<<'\n'; //unable to output int ?

    //--------------------------

    std::cout<<improved::strdup(string)<<'\n'; //works with no issues ---
    std::cout<<improved::findx(string,phrase)<<'\n';
    std::cout<<improved::strcmp(string,phrase)<<'\n';//---

    std::cout<<improved::strdup(phrasearr)<<'\n'; //stacks phrasearr before stringarr so phrasearr becomes "WorldHello,WWorld!".
    std::cout<<improved::findx(stringarr,phrasearr)<<'\n'; //stacks phrasearr before stringarr so phrasearr becomes "WorldHello,WWorld!". returns null
    std::cout.clear(); //null ptr messes with cout??
    int test2 {improved::strcmp(stringarr,phrasearr)};
    std::cout<<improved::strcmp(stringarr,phrasearr)<<test2<<'\n'; //unable to output int ?

    delete[] string;
    delete[] phrase;
}