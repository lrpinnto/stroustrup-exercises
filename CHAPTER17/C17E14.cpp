//CHAPTER 17 EX 14

#include <iostream>

using namespace std;

class Link
{
public:
    string value;
    Link(const string& v, Link* s = nullptr)
        : value{v}, succ{s} {
            if(!succ) succ=this;  //single linked list have to be circular otherwise we reach a deadend at the last entry
        }

    Link* add(Link* n);
    //Link* insert(Link* n);
    Link* find(const string& s);
    const Link* find(const string& s) const;
    Link* erase();
    Link* advance(int n) const;

    Link* next() const { return succ;}
private:
    Link* succ;
};

Link* Link::add(Link* n)
{
    if(n==nullptr) return this;
    if(this==nullptr) 
    {
        n->succ=n;
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
    this->value=succ->value;
    this->succ=succ->succ;
    p->succ=nullptr;
    return this;
}

Link* Link::find(const string& s)
{
    Link* p = this;
    Link* p_copy {p};
    while(p)
    {
        if(p->value==s) return p;
        p=p->succ;
        if(p==p_copy) break; //full loop
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
    cout<<h2->value<<'\n';
}