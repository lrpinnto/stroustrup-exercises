//Chapter 20 Ex 18, 19

//18. Define a range-checked iterator for vector ( a random-access iterator )
//19. Define a range-checked iterator for list (a bidirectional iterator )

#include <iostream>
#include <list>
#include <vector>

/*
Random-access iterator
We can iterate forwared (using ++) and backward (using --) and read an write (unless the elemtns are const) elemnt values using * or [].
We can substrcipt and add an ineger toa a random-access iterator using + and subtract an integer using -. 
We can find the distance between two random-access iterators to the same sequence by subtracting one from the other. 
This is the kind of iterator that vector offers. 
*/

/*
bidectional iterator
We can iterate forward (using ++) and backward (using --) and read and write (unless the elements are const) element values using *. 
This is the kind of itrator that list, map and set offer, If (*p).m is valid, p->m can be used as a shorthand.
*/

template<typename T>
class Vector : public std::vector<T>
{
public:
    using value_type = T ;
    using size_type = unsigned int;

    class iterator;
    class const_iterator; //to be done

    iterator begin() {return iterator(std::vector<T>::data(), *this);}
    iterator end() { return iterator(std::vector<T>::data() + std::vector<T>::size(), *this);}
};

template<typename Elem>
class Vector<Elem>::iterator 
{
private:
    value_type* curr;
    int index;
    Vector<Elem>& vec;
    void range_check(int val = 0) const
    {
        int ind {index + val};//"pretend" index for operator[] range check
        if(ind >= vec.size() || ind < 0)
            throw std::out_of_range("Index out of range");
    }
public:
    iterator(Elem* p, Vector<Elem>& v)
        :curr{p}, index{0}, vec{v} 
        {
            int counter {0};
            for (auto i = vec.data() ; i!=curr; i++)
            {
                counter++;
            }
            index=counter;
        }
    iterator& operator++() {++index; ++curr; return *this;}
    iterator& operator--() {--index; --curr; return *this;}
    Elem& operator*() const {range_check() ;return *curr; }
    Elem* operator->() const {range_check(); return curr; }

    Elem& operator[](int n) const {range_check(n); return *(curr+n); }

    bool operator==(const iterator& b) const { return curr==b.curr;}
    bool operator!=(const iterator& b) const { return curr!= b.curr; }

    iterator& operator+(int n) {index+=n; curr+=n; return *this; } 
    iterator& operator-(int n) {index-=n; curr-=n; return *this; } 

    int operator-(const iterator& it) const { return index-it.index; } 
};

template<typename T>
class List : public std::list<T>
{
public:
    using value_type = T ;
    using size_type = unsigned int;

    class iterator;
    class const_iterator; //to be done

    iterator begin() {return iterator(std::list<T>::begin(),*this,true);}
    iterator end() { return iterator(std::list<T>::end(),*this,false,true);}
};

template<typename Elem> //this iterator has been implemented to not allow iterations after .end() and before begin()
class List<Elem>::iterator 
{
private:
    typename std::list<Elem>::iterator curr;
    bool endSwitch; 
    bool beginSwitch;
    List<Elem>& lis;
public:
    iterator(typename std::list<Elem>::iterator it, List<Elem>& l, bool beginSwitchh = false, bool endSwitchh = false)
        :curr{it}, lis{l}, beginSwitch{beginSwitchh}, endSwitch{endSwitchh} {}
    iterator& operator++()  //only allow operators to function inside list space;
    {
        if(!endSwitch) 
        {
            if(beginSwitch) beginSwitch=false;
            ++curr;
            if(*this==lis.end()) endSwitch=true;
        }
        return *this;
    }
    iterator& operator--() 
    {
        if(!beginSwitch)
        {
            if(endSwitch) endSwitch=false; 
            --curr;
            if(*this==lis.begin()) beginSwitch=true;
        } 
        return *this;
    }
    Elem& operator*() const {if(endSwitch) throw std::out_of_range("Attempting to dereference end()"); return *curr; } //dereferencing end() 
    Elem* operator->() const {return &(*curr); }                                                                       //is undefined and dangerous

    bool operator==(const iterator& b) const { return curr==b.curr;}
    bool operator!=(const iterator& b) const { return curr!= b.curr; }
};

int main()
{
    std::cout<<"##############\t vector:";
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    for (auto num : a) std::cout<<num<<" ";
    std::cout<<'\n';
    auto x {a.end()};
    //range check test:
    try {std::cout<<*(x);}
    catch(const std::exception& e)
    {
        std::cerr << "can't dereference .end() therefore : " << e.what() << '\n';
    }
    std::cout<<x[-1]<<'\n';
    //int subtraction test
    auto h {x-7};
    std::cout<<*h<<'\n';
    //distance test, should be 0 since both are at the same element:
    std::cout<<x-h<<'\n';
    //write test
    h[0]=3000;
    //both h and x are pointing to the same element at this point, therefore x should display 3000;
    std::cout<<*x<<'\n';
    std::cout<<"##############\t list:";
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    for (auto num : l) std::cout<<num<<" ";
    std::cout<<'\n';
    auto k {l.end()};
    //range check test:
    for (int i = 0; i < 10; i++)
    {
        --k;
        std::cout<<*k;
    }
    std::cout<<'\n';
    for (int i = 0; i < 10; i++)
    {
        ++k;
        try {std::cout<<*k;}           //dereferencing end(), although it shouldnt be done because it's undefined behavior. 
        catch(const std::exception& e) //it does return the last element on the list (in my implementation) or the default value for the container (int()=0)
        {                              //if the list is empty 
            std::cerr << "end()";  
        }
    }                   
    std::cout<<'\n';    
    //write test
    --k; //to avoid being at end()
    *k=3000;
    for (auto num : l) std::cout<<num<<" ";   
    /*
    List<Vector<int>> g;
    auto r {g.begin()};
    r->push_back(10); //operator->() test    //BUG: operator->() not working properly 
    std::cout<<r->size();*/
}