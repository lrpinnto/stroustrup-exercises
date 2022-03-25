#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

struct out_of_range : std::out_of_range {	// enhanced vector range error reporting
	int index;
	out_of_range(int i) :std::out_of_range("Range error: "+std::to_string(i)), index(i) { }
};

/*template<typename T, typename A>
struct vector_base
{
    A alloc;
    T* elem;
    int sz;
    int space;

    vector_base(const A& a, int n)
        :alloc{a},elem{alloc.allocate(n)},sz{n},space{n}{}
    ~vector_base() {alloc.deallocate(elem,space);}
};*/


template<typename T> class allocator
{
public:
    T* allocate(int n){return (T*) malloc(n * sizeof(T));}
    void deallocate(T* p, int n){free(p);}

    void construct(T* p, const T& v){new(p) T{v};}
    void destroy(T* p){p->~T();}
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
    vector(std::initializer_list<T> lst)
        :sz{static_cast<int>(lst.size())},elem{new T[sz]},space{static_cast<int>(lst.size())}
    {
        std::copy(lst.begin(),lst.end(),elem);
    }

    vector(const vector& arg)
        :sz{arg.sz},elem{new double[arg.sz]}
    {
        std::copy(arg.elem,arg.sz,elem);
    }
    vector& operator=(const vector& a)
    {
        double* p=new double[a.sz];
        std::copy(a.elem,a.elem.sz,p);
        delete[] elem;
        elem=p;
        sz=a.sz;
        return *this;
    }

    vector(vector&& a)
        :sz{a.sz},elem{a.elem}
    {
        a.sz=0;
        a.elem=nullptr;
    }
    vector& operator=(vector&& a)
    {
        delete[] elem;
        elem=a.elem;
        sz=a.sz;
        a.elem=nullptr;
        a.sz=0;
        return *this;
    }

    ~vector(){ delete[] elem;}

    T& operator[](int n) {return elem[n];}
    const T& operator[](int n) const {return elem[n];}

    int size() const {return sz;}
    int capacity() const {return space;}

    void resize(int newsize,T val = T());
    void push_back(const T& d);
    void reserve(int newalloc);

    T& at(int n){ if(n<0||sz<=n)throw out_of_range(n); return elem[n]; }
    const T& at(int n) const{ if(n<0||sz<=n)throw out_of_range(n); return elem[n]; }
};