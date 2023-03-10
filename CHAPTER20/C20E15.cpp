//CHAPTER 20 EX 15, 16, 17
/*
15: Define a pvector to be like a vector of pointer except that it contains pointers to objects and its destructor deletes each object.

16: Define an ovector that is like pvector except that the [] and * operators return a reference to the object pointed to by an element rathe than the pointer.

17: Define an ownership_vecor that holds pointers to objects like pvector but provides a mechanism for the user to decide which objects are owned by the vector
(i.e., which onbjects are deleted buy the destructor).
*/

#include "../CHAPTER19/vector.h"
#include <vector>
#include "../CHAPTER19/tracer.h"

template<typename T>
class pvector  //exercise 15
{
public:
    using size_type = unsigned long;
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;
private:
    std::vector<value_type*> v;
public:
    pvector(){} 
    
    ~pvector(){ for(auto p : v) delete p; }

    //No assigment or copy since we are handling pointers and if one of the owners of the vector goes out of scope, the pointers will be deleted

    pvector(const pvector&)= delete;         
    pvector& operator=(const pvector&) = delete; 
    
    pvector(pvector&&)=delete;             
    pvector& operator=(pvector&&)=delete; 

    value_type* operator[](int n){return v[n];}
    const value_type* operator[](int n) const {return v[n];}

    iterator begin() {return v.begin();}
    const_iterator begin() const {return v.begin();}
    iterator end() {return v.end();}
    const_iterator end() const {return v.end();}

    void push_back(value_type newValue)
    {
        v.push_back(new value_type {newValue});
    }

    size_type size() const {return v.size();}
};

template<typename T>
class ovector : pvector<T>   //exercise 16
{
public:
    using value_type = T;
    using pvector<T>::push_back;
    using pvector<T>::begin;

    value_type& operator[](int n){return *(pvector<T>::operator[](n));}
    const value_type& operator[](int n) const {return *(pvector<T>::operator[](n));}
    value_type& operator*(){return *(pvector<T>::operator[](0));}
};

void ex15()
{
    std::cout<<"Going inside scope ex15\n";
    pvector<int> a;
    a.push_back(34);
    a.push_back(20);
    std::cout<<a[0]<<" "<<*(a[0])<<" "<<a[1]<<" "<<*(a[1])<<'\n';

    pvector<Tracer> x;
    x.push_back(Tracer("Constructor 1","Destructor 1"));
    x.push_back(Tracer("Constructor 2","Destructor 2"));
    std::cout<<"Going out of scope ex15\n";
}

void ex16()
{
    std::cout<<"Going inside scope ex16\n";
    ovector<int> a;
    a.push_back(34);
    a.push_back(20);
    std::cout<<a[0]<<" "<<a[1]<<" "<<*a<<" "<<*(a)<<'\n';

    pvector<Tracer> x;
    x.push_back(Tracer("Constructor 1","Destructor 1"));
    x.push_back(Tracer("Constructor 2","Destructor 2"));
    std::cout<<"Going out of scope ex16\n";
}

int main()
{
    std::cout<<"main()\n";
    ex15();
    ex16();
    std::cout<<"main() out\n";
}
