//CHAPTER 18 EX 11

#include <iostream>
#include <algorithm>
//https://en.wikipedia.org/wiki/Skip_list
using namespace std;

class Link //unlike C17E14.cpp, it will end on a nullptr
{
public:
    int value;
    Link(const int& v, Link* s = nullptr, Link* p = nullptr)
        : value{v}, succ{s}, parent{p} {}

    Link* add(Link* n);
    //Link* insert(Link* n);
    Link* find(const int& s);
    const Link* find(const int& s) const;
    Link* erase();
    Link* advance(int n) const;

    Link* next() const { return succ;}
    Link& operator=(const Link*); //copy assignment (to move the pointer)

    Link* get_parent(){return parent;}
    void set_parent(Link* p){parent=p;}
private:
    Link* succ;
    Link* parent; //level below
};
Link& Link::operator=(const Link* a)
{
    succ=a->succ;
    value=a->value;
    return *this;
}

class Skip_list
{
private:
    Link level[4];
    int* list;
public:
    Skip_list(initializer_list<int> lst);
    ~Skip_list();
    Link print() {return *level;}
    Link* find(int);
    Link* add(int);
    Link* erase(int);
};

Skip_list::Skip_list(initializer_list<int> lst)
    : level{0,0,0,0}, list{new int[lst.size()]} //placeholders
{
    std::copy(lst.begin(),lst.end(),list); //copy lst to list
    std::sort(list,list+lst.size());
    Link* p {&level[0]}; //used to keep indexes in check
    p->value=list[0];
    for (size_t i = 1; i < lst.size(); i++) //check for size_t functionality
    {
        p=p->add(new Link {list[i]});
    }
    //make all nodes level 1
    level[1].value=level[0].value; //limit of 4 levels?
    level[2].value=level[0].value; //if not, take out while condition of "j<3"
    level[3].value=level[0].value;
    level[1].set_parent(&level[0]);
    level[2].set_parent(&level[1]);
    level[3].set_parent(&level[2]);

    int j {0};
    p=level[j].next();
    Link* p_nextlevel {&level[j+1]};
    bool promoted {false};
    while(p && j<3) {//the number of nodes at level j > 1 
        for(int i=1 ; p;i++){
            if (i%2!=0 && p->next()!=nullptr)
            {
                if(rand()%2==1){ //randomly choose whether to promote it to level j+1
                    p_nextlevel=p_nextlevel->add(new Link{p->value,nullptr,p});
                    promoted=true;
                }
                else promoted=false;
            }
            else if(i%2==0 && !promoted) {//i is even and node i-1 was not promoted
                p_nextlevel=p_nextlevel->add(new Link{p->value,nullptr,p});
                promoted=true;
            }
            else promoted=false;
            if(p->next())
                p=p->next();
            else break;
        }
        j++;
        p=level[j].next();
        p_nextlevel=&level[j+1];
    }
}

Skip_list::~Skip_list()
{
    delete[] list;
}

Link* Skip_list::find(int num)
{
    Link* p {&level[3]};
    Link* p_lastnode {nullptr};
    while(num>p->value)
    {
        p_lastnode=p;
        if(p->next())
        {
            p=p->next();
        }
        else
        {
            p=p->get_parent()->next();
        }
    }
    while(p->next() ? p->next()->value>num : true)
    {
        if(p->value>p_lastnode->value)
            p=p_lastnode->get_parent();
        else
            p=p->get_parent();
    }
    while(num!=p->value)
    {
        
        if(!(p->next()) || p->next()->value>num)
        {
            p=p->get_parent();
        }
        else p=p->next();
        if(!p) return nullptr;
    }
    return p;
}
Link* Skip_list::add(int num)
{

}
Link* Skip_list::erase(int num)
{

}

Link* Link::add(Link* n)
{
    if(n==nullptr) return this;
    if(this==nullptr) 
    {
        n->succ=nullptr;
        return n;
    }
    n->succ=this->succ;
    this->succ=n;
    return n;
}

Link* Link::erase()
{
    if(this==nullptr) return nullptr;
    Link* p {succ};
    this->value=succ->value; // if succ is nullptr then this becomes nullptr as well???
    this->succ=succ->succ; //same thing??
    p->succ=nullptr; //same thing?
    return this;
}

Link* Link::find(const int& s)
{
    Link* p = this;
    Link* p_copy {p};
    while(p)
    {
        if(p->value==s) return p;
        p=p->succ;
    }
    return nullptr;
}


Link* Link::advance(int n) const
{
    Link* p {nullptr};
    bool first_pass {true};
    if(this==nullptr) return nullptr;
    if (0<n)
    {
        while(n--)
        {
            if(succ==nullptr) return nullptr;

            if(first_pass) {p=succ;first_pass=false;}
            else p=p->succ;
        }
    }
    return p;
}

void print_all(Link* p)
{
    Link* p_copy{p};
    cout<<"{";
    while (p)
    {
        cout<<p->value;
        if(p->next()==p_copy) break; //full loop
        if(p=p->next()) cout<<", ";
    }
    cout<<"}";
}

int main()
{
    Skip_list l {15,2,3,4,30,69,12,1,5,6,7,8,9,10,11,13,14};
    Link* p {l.find(1)}; //edge case to fix
    cout<<p->value;
}