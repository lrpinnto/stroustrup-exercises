//Chapter 19 Ex 08 an 09
/*TODO: EX FINISH 08 AND START 09*/
#include <vector>
//p=malloc(s)
//Allocate s uninitialized bytes on the free store; p=0 if s bytes could not be allocated.
//free(p)
//Deallocate the memory pointed to by p; p must be a pointer returned by malloc(), calloc(), or realloc().

/*
Placement new

If placement-params are provided, they are passed to the allocation function as additional arguments. Such allocation functions are known as "placement new", 
after the standard allocation function void* operator new(std::size_t, void*), which simply returns its second argument unchanged. 
*/

template<typename T> class allocator { //EXAMPLE FROM 19.3.7
public:
    T* allocate(int n); // allocate space for n objects of type T
    void deallocate(T* p, int n) { for(int i = 0;i<n;n++){free(p)}; p++;} // deallocate n objects of type T starting at p //(is for cycle incorrect?)
    void construct(T* p, const T& v) { new(p) T(v); } // construct a T with the value v in p //double check member function expression
    void destroy(T* p) { p->~T(); } // destroy the T in p //double check member function expression
};


// allocate space for n objects of type T
template<typename T> T* allocator<T>::allocate(int n)
{
    T* p = static_cast<T*>(malloc(n*sizeof(T)));
    if (p==0) error("allocate: could not allocate memory");
    return p;
}

template<typename T>
struct Vector : public std::vector<T>
{
    using size_type = typename std::vector<T>::size_type;
    using vector<T>::vector;

    T& operator[](size_type i)
    {
        if(i<0 || this->size()<=i) throw Range_error{i};
        return std::vector<T>::operator[](i);
    }

    const T& operator[](size_type i) const
    {
        if (i<0 || this->size()<=i) throw Range_error{i};
        return std::vector<T>::operator[](i);
    }
};

int main()
{

}