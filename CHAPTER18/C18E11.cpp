//CHAPTER 18 EX 11

#include <iostream>
#include <algorithm>
//https://en.wikipedia.org/wiki/Skip_list
using namespace std;

class Link //unlike C17E14.cpp, it will end on a nullptr
{
public:
    int value;
    Link(const int& v, Link* s = nullptr)
        : value{v}, succ{s} {}

    Link* add(Link* n);
    //Link* insert(Link* n);
    Link* find(const int& s);
    const Link* find(const int& s) const;
    Link* erase();
    Link* advance(int n) const;

    Link* next() const { return succ;}
private:
    Link* succ;
};

class Skip_list
{
private:
    Link level[4];
    int* list;
public:
    Skip_list(initializer_list<int> lst);
    ~Skip_list();
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
    //https://en.wikipedia.org/wiki/Skip_list
    int j {0};
    bool promoted {false};
    while(&level[j] && level[j].next()) {//the number of nodes at level j > 1 
        for(int j=0 ; j<sizeof(level)/sizeof(Link);j++){
            if (level[j].value%2!=0 && level[j].next()!=nullptr)
                if(rand()%2==1){ //randomly choose whether to promote it to level j+1
                    level[j+1].add(new Link{level[j].value});
                    promoted=true;
                }
            else if(level[j].value%2==0 && !promoted) {//i is even and node i-1 was not promoted
                level[j+1].add(new Link{level[j].value});
                promoted=true;
            }
        }
        j++;
    }
    //--
}

Skip_list::~Skip_list()
{
    delete[] list;
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

    Skip_list l {15,2,3,4};
    /*
    Link* norse_gods = new Link("Thor");
    norse_gods=norse_gods->add(new Link{"Odin"});
    norse_gods=norse_gods->add(new Link{"Zeus"});
    norse_gods=norse_gods->add(new Link{"Freia"});
    
    Link* greek_gods = new Link("Hera");
    greek_gods=greek_gods->add(new Link{"Athena"});
    greek_gods=greek_gods->add(new Link{"Mars"});
    greek_gods=greek_gods->add(new Link{"Poseidon"});

    Link* p = greek_gods->find("Mars");
    if(p) p->value="Ares";

    Link* p2 = norse_gods->find("Zeus");
    if(p2)
    {
        if(norse_gods!=p2) norse_gods=p2;
        p2->erase();
        greek_gods=greek_gods->add(new Link{"Zeus"});
    }

    print_all(norse_gods);
    cout<<'\n';
    print_all(greek_gods);
    cout<<'\n';

    Link* const h = greek_gods->find("Zeus");
    //advance test
    cout<<h->value<<'\n';
    Link* const h2=h->advance(2);
    cout<<"2x"<<'\n';
    cout<<h2->value<<'\n';*/


}

/*
make all nodes level 1

*/