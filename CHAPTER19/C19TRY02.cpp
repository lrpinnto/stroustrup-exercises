//Chapter 19 Try this 02 
#include "vector.h"
#include <iostream>

void suspicious(vector<int>& v, int s)
{
    int* p = new int[s];
    vector<int>v1(2);
    try{
        if(s) p[s]=v1.at(s);
    }catch(...)
    {
        std::cout<<"Deleting p...\n";
        delete[] p;
        throw;
    }
    int* q = new int[s];
    vector<double> v2;
    try{
        if(s) q[s]=v2.at(s);
    }catch(...)
    {
        std::cout<<"Deleting p...\n";
        delete[] p;
        std::cout<<"Deleting q...\n";
        delete[] q;
        throw;
    }
    std::cout<<"Deleting p...\n";
    delete[] p;
    std::cout<<"Deleting q...\n";
    delete[] q;
}

int main()
{
    vector<int>a{1,2};
    a.push_back(1);
    std::cout<<"--first try test--\n";
    try
    {
        suspicious(a,3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"--second try test--\n";
    try
    {
        suspicious(a,1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"--no error test--\n";
    suspicious(a,0);
}