//CHAPTER 20 TRY THIS 05

#include "../CHAPTER19/vector.h"

//Could've perhaps used inheritance instead of rewritting everything?
//recheck to see if it's possible

template<typename T, typename A = allocator<T>> 
struct vector_try
{
private:
    A alloc;
    int sz;
    T* elem;
    int space;
public:
    vector_try() : sz{0},elem{nullptr},space{0} {}
    explicit vector_try(int s) :sz{s},elem{new T[s]},space{s}
    {
        for (int i = 0; i < sz; ++i)
        {
            elem[i]=0;
        }
    }
    vector_try(std::initializer_list<T> lst)
        :sz{static_cast<int>(lst.size())},elem{new T[sz]},space{static_cast<int>(lst.size())}
    {
        std::copy(lst.begin(),lst.end(),elem);
    }

    vector_try(const vector_try& arg)
        :sz{arg.sz},elem{new double[arg.sz]}
    {
        std::copy(arg.elem,arg.sz,elem);
    }
    vector_try& operator=(const vector_try& a)
    {
        double* p=new double[a.sz];
        std::copy(a.elem,a.elem.sz,p);
        delete[] elem;
        elem=p;
        sz=a.sz;
        return *this;
    }

    vector_try(vector_try&& a)
        :sz{a.sz},elem{a.elem}
    {
        a.sz=0;
        a.elem=nullptr;
    }
    vector_try& operator=(vector_try&& a)
    {
        delete[] elem;
        elem=a.elem;
        sz=a.sz;
        a.elem=nullptr;
        a.sz=0;
        return *this;
    }

    ~vector_try(){ delete[] elem;}

    T& operator[](int n) {return elem[n];}
    const T& operator[](int n) const {return elem[n];}

    int size() const {return sz;}
    int capacity() const {return space;}

    void resize(int newsize,T val = T());
    void push_back(const T& d);
    void reserve(int newalloc);

    T& at(int n){ if(n<0||sz<=n)throw out_of_range(n); return elem[n]; }
    const T& at(int n) const{ if(n<0||sz<=n)throw out_of_range(n); return elem[n]; }

    void push_front(const T& val);
};

template<typename T, typename A>
void vector_try<T,A>::reserve(int newalloc)
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
void vector_try<T,A>::push_back(const T& val)
{
    if(space==0) reserve(8);
    else if (sz==space) reserve(2*space);
    alloc.construct(&elem[sz],val);
    ++sz;
}

template<typename T, typename A>
void vector_try<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) alloc.construct(&elem[i],val);
    for (int i = newsize; i<sz; ++i) alloc.destroy(&elem[i]);
    sz=newsize;
}

template<typename T, typename A>
void vector_try<T,A>::push_front(const T& val)
{
    if(space==0) reserve(8);
    else if (sz==space) reserve(2*space);
    for (int i = sz; i > 0; --i)
    {
        alloc.construct(&elem[i],elem[i-1]);
    }
    alloc.construct(&elem[0],val);
    ++sz;
}

int main()
{
    vector_try<int> abc {1,2,3};
    abc.push_front(9);
    for (int i = 0; i < abc.size(); i++)
    {
        std::cout<<abc[i];
    }
}

/*
Push_front(), on the other hand, would require to somehow write the new element BEFORE all the current ones, at position [0] - however that's not trivial, since your array position [0] is occupied already. Push_front() would cause the whole array to be copied anew, so that its front can be modified. It would be an inefficient operation for which std::vector<> class is not designed.

You can still do it, of course, by calling

std::vector::insert(begin(), 1, val)

But it'll cause the whole array to be copied just to add a single element.

https://stackoverflow.com/questions/51499422/why-doesnt-stdvectorpush-front-exist
*/