//CHAPTER 19 EX 08 & 09
#include "vector.h"

/*
From the Book:
B.11.4
p=malloc(s)
    Allocate s uninitialized bytes on the free store; p=0 if s bytes could not be allocated.
free(p)
    Deallocate the memory pointed to by p; p must be a pointer returned by malloc(), calloc(), or realloc().

Note that malloc(), etc. do not invoke constructors and free() doesn't invoke destructors. Do not use these functions for types with constructors or destructors.
*/

/*
Placement new

If placement-params are provided, they are passed to the allocation function as additional arguments. Such allocation functions are known as "placement new", 
after the standard allocation function void* operator new(std::size_t, void*), which simply returns its second argument unchanged. 
*/

/*
Explicit call of destructor

Use the obj.~ClassName() Notation to Explicitly Call a Destructor Function.
https://www.delftstack.com/howto/cpp/call-destructor-in-cpp/
*/

/*
template<typename T> 
class allocator { //EXAMPLE FROM 19.3.7
public:
    T* allocate(int n);                 // allocate space for n objects of type T
    void deallocate(T* p, int n);       // deallocate n objects of type T starting at p 
    void construct(T* p, const T& v);   // construct a T with the value v in p 
    void destroy(T* p);                 // destroy the T in p 
};
*/

template<typename T> 
class allocator_malloc : public allocator<T>          //check vector.h for reference
{ };

/*
template<typename T> //EXAMPLE FROM 19.4.2
                    //Doesn't make sense to use this version due to inherithed constructor
struct Vector : public std::vector<T>
{
    using size_type = typename std::vector<T>::size_type;
    using std::vector<T>::vector;       //use vector<T>'s constructors ($20.5)

    T& operator[](size_type i)         //rather than return at(i);
    {
        if(i<0 || this->size()<=i) throw out_of_range(i);
        return std::vector<T>::operator[](i);
    }

    const T& operator[](size_type i) const
    {
        if (i<0 || this->size()<=i) throw out_of_range(i);
        return std::vector<T>::operator[](i);
    }
};*/

template<typename T, typename A = allocator_malloc<T>>
class vector_malloc 
{
private:
    A alloc;
    int sz;
    T* elem;
    int space;
public:
    vector_malloc() :elem{alloc.allocate(0)},sz{0},space{0}{}  //https://stackoverflow.com/questions/2022335/whats-the-point-of-malloc0
    explicit vector_malloc(int n)
        :elem{alloc.allocate(n)},sz{n},space{n}{}
    ~vector_malloc() {alloc.deallocate(elem,space);}

    vector_malloc(const vector_malloc&);            //not implemented
    vector_malloc& operator=(const vector_malloc&); // copy assignment EX 9
    
    vector_malloc(vector_malloc&&);             //not implemented
    vector_malloc& operator=(vector_malloc&&); //not implemented

    T& operator[](int n){return elem[n];}
    const T& operator[](int n) const {return elem[n];}

    int size() const {return sz;}
    int capacity() const {return space;}

    void resize(int newsize, T val = T());
    void push_back(const T& d);
    void reserve(int newalloc); //Shoudn't reserve be private?

    T& at(int n){ if(n<0||sz<=n)throw out_of_range(n); return elem[n]; }
    const T& at(int n) const{ if(n<0||sz<=n)throw out_of_range(n); return elem[n]; }
};

template<typename T, typename A>
void vector_malloc<T,A>::reserve(int newalloc)
{
    if(newalloc<=space) return;
    T* p = alloc.allocate(newalloc);
    for(int i=0;i<sz; ++i) alloc.construct(&p[i],elem[i]);
    for(int i=0; i<sz; ++i) alloc.destroy(&elem[i]);
    alloc.deallocate(elem,space);
    elem=p;
    space=newalloc;
}

template<typename T, typename A>
void vector_malloc<T,A>::push_back(const T& val)
{
    if(space==0) reserve(8);
    else if (sz==space) reserve(2*space);
    alloc.construct(&elem[sz],val);
    ++sz;
}

template<typename T, typename A>
void vector_malloc<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val);
    for (int i = newsize; i<sz; ++i) alloc.destroy(&elem[i]);
    sz=newsize;
}

//EX 9
template<typename T, typename A>
vector_malloc<T,A>& vector_malloc<T,A>::operator=(const vector_malloc& a)
{
    if(this==&a) return *this;

    if(a.sz<=space)
    {
        for(int i=0; i<a.sz; ++i) alloc.construct(&elem[i],a.elem[i]);
        sz=a.sz;
        return *this;
    }

    T* p = alloc.allocate(a.sz);
    for(int i=0; i<a.sz; ++i) alloc.construct(&p[i],a.elem[i]);
    for(int i=0; i<sz; ++i) alloc.destroy(&elem[i]);  //Do I really need to explicitly call destructor?
    alloc.deallocate(elem,space);
    space = sz = a.sz;
    elem = p;
    return *this;
}

int main()
{
    //PUSH BACK AND CONSTRUCTOR TEST
    vector_malloc<int> a (2);
    a.push_back(20);
    std::cout<<a[2];
    vector_malloc<int> b;
    //COPY ASSIGN TEST
    b=a;
    std::cout<<'\n';
    std::cout<<b[2]<<'='<<a[2]<<'\n';
    //RESERVE / RESIZE TEST
    vector_malloc<double> c;
    c.resize(4000,1.1);
    std::cout<<c.at(3999);
}