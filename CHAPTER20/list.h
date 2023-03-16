// As described in the book 20.4.1-2

template<typename Elem>
struct Link
{
    Link* prev;
    Link* succ;
    Elem val;
};

template<typename Elem>
class list
{
public:
    class iterator;

    iterator begin();
    iterator end();

    iterator insert(iterator p, const Elem& v);
    iterator erase(iterator p);

    void push_back(const Elem& v);
    void push_front(const Elem& v);
    void pop_front();
    void pop_back();

    Elem& front();
    Elem& back();
    //For EX 12 and 13
    list();
    ~list();
    void clear();
    //----------------
private:
    Link<Elem>* first;
    Link<Elem>* last;
};

template<typename Elem>
class list<Elem>::iterator
{
    Link<Elem>* curr;
public:
    iterator(Link<Elem>* p)
        :curr{p} {}
    
    iterator& operator++() {curr=curr->succ; return *this;}
    iterator& operator--() {curr=curr->prev; return *this;}
    Elem& operator*() {return curr->val;}

    bool operator==(const iterator& b) const { return curr==b.curr;}
    bool operator!=(const iterator& b) const { return curr!=b.curr;} 
};