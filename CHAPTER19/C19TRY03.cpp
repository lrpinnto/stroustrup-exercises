//Chapter 19 try this 03
//LINK to header vector
#include <memory>

using namespace std;

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;
    unique_ptr<T> p= alloc.allocate(newalloc)
    for(int i=0;i<sz;++i) alloc.construct(&p[i],elem[i]);
    for(int i=0;i<sz;++i) alloc.destroy(&elem[i]);
    alloc.deallocate(elem,space);
    elem=p.release();
    space=newalloc;
}
