//Chapter 19 Try this 02 
#include "vector.h"
#include <iostream>

//Vector definition to avoid conflicts with TRY03
template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if(newalloc<=space) return;
    T* p=alloc.allocate(newalloc);
    for(int i=0; i<sz; ++i) alloc.construct(&p[i],elem[i]);
    for(int i=0; i<sz; ++i) alloc.destroy(&elem[i]);
    alloc.deallocate(elem,space);
    elem=p;
    space=newalloc;
    /*
    if(newalloc<=this->space) return;
    vector_base<T,A> b(this->alloc,newalloc);
    std::unintilized_copy(b.elem,&b.elem[this->sz],this->elem);
    for (int i = 0; i < this->sz; ++i)
    {
        this->alloc.destroy(&this->elem[i]);
    }
    std::swap<vector_base<T,A>>(*this,b);
    */
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& val)
{
    if(space==0) reserve(8);
    else if (sz==space) reserve(2*space);
    alloc.construct(&elem[sz],val);
    ++sz;
}

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for(int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val);
    for(int i=newsize; i<sz; ++i) alloc.destroy(&elem[i]);
    sz=newsize;
}
//------------------------

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