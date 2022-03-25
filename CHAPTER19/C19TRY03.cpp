//Chapter 19 try this 03
#include <memory>
#include "vector.h"

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;
    std::unique_ptr<T> p {alloc.allocate(newalloc)};
    for(int i=0;i<sz;++i) alloc.construct(&(p.get()[i]),elem[i]);
    for(int i=0;i<sz;++i) alloc.destroy(&elem[i]);
    alloc.deallocate(elem,space);
    elem=p.release();
    space=newalloc;
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

int main()
{
    vector<int>abc {1,2,3,4};
    abc.push_back(5);
    std::cout<<abc[4];
}