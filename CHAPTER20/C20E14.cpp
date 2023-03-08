//CHAPTER 20 EX 14

#include <cstddef>
#include <iostream>

//Need to finish erase, insert, popfront and back... Moving on

template<typename T>
class slist 
{
public:
    class Link;
private:
    Link* head;
    size_t size;
public:
    slist()
        : head{nullptr}, size{0} {}
    ~slist() {clear();}

    using value_type = T;

    class iterator;
    class const_iterator;

    iterator begin() {return iterator(head);}
    const_iterator begin() const;
    iterator end() {return iterator(nullptr);}
    const_iterator end() const;

    iterator insert(iterator p, const T&);
    iterator erase(const T&);
    bool search(const T&) const;
    void clear();

    void push_back(const T&);
    void push_front(const T&);
    void pop_front();
    void pop_back();

    T& front();
    T& back();

    size_t getSize() const { return size; }
};

template<typename T>   
void slist<T>::push_front(const T& newData)
{
    Link* newLink {new Link(newData)};
    if (!head)
    {
        head = newLink;
    }
    else
    {
        newLink->next = head;
        head = newLink;
    }
    size++;
}

template<typename T>   
void slist<T>::push_back(const T& newData)
{
    Link* newLink {new Link(newData)};
    if (!head)
    {
        head = newLink;
    }
    else
    {
        (head+(size-1))->next = newLink; //set last elements "next" to point to the newLink
    }
    size++;
}

/*template<typename T>   //points at the inserted element
typename slist<T>::iterator slist<T>::insert(iterator p, const T& newData)
{
    Link* newLink {new Link(newData)};
    if (!head)
    {
        head = newLink;
    }
    else
    {
        newLink->next = (++p);
        p.curr->next = newLink;
        //(head+(size-1))->next = newLink; //set last elements "next" to point to the newLink
    }
    size++;

    return iterator(newLink);
}*/

/*
template<typename T> //points to the element after the erased one
slist<T>::iterator slist<T>::erase(const T& dataToRemove)
{
    Link* prev {nullptr};
    Link* curr {head};
    while (curr)
    {
        if (curr->data == dataToRemove)
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            else
            {
                head = curr->next;
            }
            delete curr;
            size--;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return 
}*/

template<typename T>
bool slist<T>::search(const T& dataToSearch) const
{
    Link* curr {head};
    while(curr)
    {
        if (curr->data == dataToSearch)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}


template<typename T>
void slist<T>::clear()
{
    Link* curr {head};
    while (curr)
    {
        Link* temp {curr};
        curr = curr->next;
        delete temp;
    }
    head=nullptr;
    size=0;
} 

template<typename T>
class slist<T>::Link 
{
public:
    T data;
    Link* next;

    Link(const T& newData)
        : data{newData}, next(nullptr) {}
};

template<typename Elem>
class slist<Elem>::iterator //as defined in the book
{
private:
    Link* curr;
public:
    iterator(Link* p)
        :curr{p} {}
    iterator& operator++() {curr=curr->next; return *this;}
    //iterator& operator--() {curr=curr->prev; return *this;}
    Elem& operator*() { return curr->data; }

    bool operator==(const iterator& b) const { return curr==b.curr;}
    bool operator!=(const iterator& b) const { return curr!= b.curr; }
};

template<typename Elem>
class slist<Elem>::const_iterator //as defined in the book
{
private:
    Link* curr;
public:
    const_iterator(Link* p)
        :curr{p} {}
    //iterator& operator++() {curr=curr->next; return *this;}
    //iterator& operator--() {curr=curr->prev; return *this;}
    Elem& operator*() { return curr->data; }

    bool operator==(const iterator& b) const { return curr==b.curr;}
    bool operator!=(const iterator& b) const { return curr!= b.curr; }
};

template<typename T>
void printlist(slist<T>& l, std::ostream& os = std::cout)
{
    os<<"{ ";
    for (const auto& i : l)
    {
        os<<i<<' ';
    }
    os<<'}';
}

int main()
{
    slist<int> A;
    A.push_back(20);
    A.push_back(30);
    A.push_front(10);
    printlist(A);

    /*std::cout<<"pop test:\n";
    A.pop_back();
    A.pop_front();
    printlist(A);*/
}