// CHAPTER 20 EX 12

// 12.
// Complete the definition of list from 20.4.1-2 and get the high() example to run. Allocate a Link to represent one past the end.

#include "./list.h"
#include <iostream>
#include <cmath>

template<typename Elem>
list<Elem>::list()  //define empty list as begin()==end()
    :first{new Link<Elem>}, last{first} { last->prev=nullptr; last->succ=nullptr; }

template<typename Elem>
list<Elem>::~list() { clear(); }

template<typename Elem>
void list<Elem>::clear()
{
    Link<Elem>* curr {first};
    while (curr)
    {
        Link<Elem>* temp {curr};
        curr = curr->succ;
        delete temp;
    }
    first=nullptr;
    last=nullptr;
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::begin()
{
    return iterator(first);
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::end()
{
    return iterator(last);
}

template<typename Elem> //inserts element behind
typename list<Elem>::iterator list<Elem>::insert(iterator p, const Elem& v)
{
    if(p==end()) //if we have an empty list (or if we are inserting to end()), just push back and return  
    {
        push_back(v);
        auto element {end()};
        --element;
        return element;
    }
    if(p==begin())
    { 
        push_front(v);
        return begin();
    }
    auto ptr {first};
    while(ptr)
    {
        if(p==iterator(ptr)) break;
        ptr=ptr->succ;
    }
    Link<Elem>* newLink {new Link<Elem>};
    newLink->succ=ptr;
    newLink->prev=ptr->prev;
    ptr->prev=newLink;
    newLink->prev->succ=newLink;
    newLink->val=v;
    return iterator(newLink);
}
template<typename Elem>  //This implementation might be wrong but I couldnt find an easier way to find the position of p within the context of Link
typename list<Elem>::iterator list<Elem>::erase(iterator p) //since we are pretty limited with the tools we can use (bidirectional iterator)
{
    auto ptr {first};
    while(ptr)
    {
        if(p==iterator(ptr)) break;
        ptr=ptr->succ;
    }
    if(!ptr->succ) return p; //attempting to erase end(). Do nothing
    if(!ptr->prev) first=ptr->succ; //In case we delete first, it goes here
    else ptr->prev->succ=ptr->succ;
    ptr->succ->prev=ptr->prev;
    iterator it {ptr->succ};
    delete ptr;
    return iterator(it);
}

template<typename Elem>
void list<Elem>::push_back(const Elem& v)
{
    Link<Elem>* newLink {new Link<Elem>};
    newLink->prev=last->prev;
    newLink->succ=last;
    last->prev=newLink;
    if(newLink->prev) newLink->prev->succ=newLink;
    else first=newLink;
    newLink->val = v;
}

template<typename Elem>
void list<Elem>::push_front(const Elem& v)
{
    Link<Elem>* newLink {new Link<Elem>};
    newLink->succ=first;
    newLink->prev=first->prev; //should be nullptr because begin() is the first element
    first->prev=newLink;
    first=newLink;
    first->val=v;
}

template<typename Elem>
void list<Elem>::pop_front()
{
    if(begin()==end()) return; //ignore attempts at erasing empty list
    auto toDelete {begin()};
    erase(toDelete);
}

template<typename Elem>
void list<Elem>::pop_back()
{
    if(begin()==end()) return; //ignore attempts at erasing empty list
    auto toDelete {end()};
    --toDelete;
    erase(toDelete);
}

template<typename Elem>
Elem& list<Elem>::front()
{
    return first;
}

template<typename Elem>
Elem& list<Elem>::back()
{
    return last;
}

template<typename Iter>
Iter high(Iter first, Iter last)
{
    Iter high = first;
    for (Iter p= first; p!=last; ++p)
        if(*high<*p) high=p;
    return high;
}

int main()
{  //Need to write some tests...
    srand(time(0));
    list<double> l;
    for (int i = 0 ; i < 20; i++)
        l.push_back((rand()%100)+((rand()%1000)*std::pow(10,-3)));   
    for(auto& d : l)
        std::cout<<d<<' ';
    std::cout<<'\n';
    std::cout<<*high(l.begin(),l.end());
}