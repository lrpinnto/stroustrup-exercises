#include <stdexcept>
#include <iostream>
#include <string>

struct out_of_range : std::out_of_range {	// enhanced vector range error reporting
	int index;
	out_of_range(int i) :std::out_of_range("Range error: "+std::to_string(i)), index(i) { }
};

template<typename T> class allocator
{
public:
    T* allocate(int n);
    void deallocate(T* p, int n);

    void construct(T* p, const T& v);
    void destroy(T* p);
};

template<typename T, typename A = allocator<T>>
class vector
{
private:
    A alloc;
    int sz;
    T* elem;
    int space;
public:
    vector() : sz{0},elem{nullptr},space{0} {}
    explicit vector(int s) :sz{s},elem{new T[s]},space{s}
    {
        for (int i = 0; i < sz; ++i)
        {
            elem[i]=0;
        }
    }

    vector(const vector&);
    vector& operator=(const vector&);

    vector(vector&&);
    vector& operator=(vector&&);

    ~vector(){ delete[] elem;}

    T& operator[](int n) {return elem[n];}
    const T& operator[](int n) const {return elem[n];}

    int size() const {return sz;}
    int capacity() const {return space;}

    void resize(int newsize,T val = T());
    void push_back(const T& d);
    void reserve(int newalloc);

    T& at(int n){ if(n<0||sz<=n)throw out_of_range(); return elem[n]; }
    const T& at(int n) const{ if(n<0||sz<=n)throw out_of_range(); return elem[n]; }
};

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
void vector<T,A>::resize(int newsize, T val = T())
{
    reserve(newsize);
    for(int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val);
    for(int i=newsize; i<sz; ++i) alloc.destroy(&elem[i]);
    sz=newsize;
}