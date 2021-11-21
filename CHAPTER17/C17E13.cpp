//CHAPTER 17 EX 13

#include <iostream>

using namespace std;

struct God
{
    string name;
    string mythos;
    string vehicle;
    string weapon;
    God(string nname, string mmythos, string vvehicle, string wweapon)
        :name{nname},mythos{mmythos},vehicle{vvehicle},weapon{wweapon}{}
};
/*
bool operator==(const God& a,const God& b)
{
    return (a.name==b.name && a.mythos==b.mythos && a.vehicle==b.vehicle && a.weapon==b.weapon);
}*/

class Link
{
public:
    God value;
    Link(const God& v, Link* p = nullptr, Link* s = nullptr)
        : value{v}, prev{p}, succ{s} {}

    Link* add(Link* n);
    Link* add_ordered(Link* n);
    Link* insert(Link* n);
    Link* find(const string& s);
    const Link* find(const string& s) const;
    Link* erase();
    Link* advance(int n) const;

    Link* next() const { return succ;}
    Link* previous() const { return prev;}
private:
    Link* prev;
    Link* succ;
    
};

Link* Link::insert(Link* n)
{
    if(n==nullptr) return this;
    if(this==nullptr) return n;
    n->succ=this;
    if(prev) prev->succ=n;
    n->prev=prev;
    prev=n;
    return n;
}
Link* Link::add(Link* n)
{
    if(n==nullptr) return this;
    if(this==nullptr) return n;
    n->prev=this;
    if(succ) succ->prev=n;
    n->succ=succ;
    succ=n;
    return n;
}

Link* Link::add_ordered(Link* n)
{
    if(n==nullptr) return this;
    if(this==nullptr) {
        Link* p {new Link{n->value}}; //create a new, blank list
        return p;
    }
    n=new Link{n->value}; //avoids messing up linked list from n. Move gods outside of this function (according to exercise)
    Link* p {this};
    while(p){ //get to first element (no predecessor)
        if(!(p->previous())) break;
        p=p->previous();
    }
    while(p){
        if (n->value.name < p->value.name )
        {
            p=p->insert(n);
            break;
        }
        if (!(p->next())) //in case n is lexically superior to all elements of the list
        {
            p=p->add(n);
            break;
        }
        p=p->next();
    }
    return p;
}

Link* Link::erase()
{
    if(this==nullptr) return nullptr;
    if(succ)succ->prev=prev;
    if(prev)prev->succ=succ;
    return succ;
}

Link* Link::find(const string& s)
{
    Link* p = this;
    while(p)
    {
        if(p->value.name==s) return p;
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
    else if (n<0)
    {
        while (n++)
        {
            if(prev==nullptr) return nullptr;

            if(first_pass) {p=prev;first_pass=false;}
            else p=p->prev;
        }
    }
    return p;
}

void print_all(Link* const x)
{
    Link* p {x};
    cout<<"-------\n";
    while (p)
    {
        cout<<"God "<<p->value.name<<'\n'<<"Mythos: "<<p->value.mythos<<'\n'<<"Vehicle: "<<p->value.vehicle<<'\n'<<"Weapon: "<<p->value.weapon;
        if(p=p->next()) cout<<"\n\n";
    }
    cout<<"\n-------";
}

int main()
{
    Link* norse_gods = new Link{{"Thor","1","2","3"}};
    norse_gods=norse_gods->insert(new Link{{"Odin","1","2","3"}});
    norse_gods=norse_gods->insert(new Link{{"Zeus","1","2","3"}});
    norse_gods=norse_gods->insert(new Link{{"Freia","1","2","3"}});
    
    Link* greek_gods = new Link{{"Hera","1","2","3"}};
    greek_gods=greek_gods->insert(new Link{{"Athena","1","2","3"}});
    greek_gods=greek_gods->insert(new Link{{"Mars","1","2","3"}});
    greek_gods=greek_gods->insert(new Link{{"Poseidon","1","2","3"}});

    greek_gods=greek_gods->add_ordered(new Link{{"Abch","1","2","3"}});

    while(greek_gods){ //get to first element (no predecessor)
        if(!(greek_gods->previous())) break;
        greek_gods=greek_gods->previous();
    }

    print_all(greek_gods);
    cout<<'\n';

    Link* lexi_norse {nullptr};
    Link* lexi_greek {nullptr};

    while(norse_gods){ //get to first element (no predecessor)
        if(!(norse_gods->previous())) break;
        norse_gods=norse_gods->previous();
    }

    while (greek_gods)
    {
        lexi_greek=lexi_greek->add_ordered(greek_gods);
        greek_gods=greek_gods->next();
    }

    while (norse_gods)
    {
        lexi_norse=lexi_norse->add_ordered(norse_gods);
        norse_gods=norse_gods->next();
    }

    while(lexi_greek){ //get to first element (no predecessor)
        if(!(lexi_greek->previous())) break;
        lexi_greek=lexi_greek->previous();
    }
    while(lexi_norse){ //get to first element (no predecessor)
        if(!(lexi_norse->previous())) break;
        lexi_norse=lexi_norse->previous();
    }
    cout<<"Greek gods lexical";
    print_all(lexi_greek);
    cout<<'\n';
    cout<<"Norse gods lexical";
    print_all(lexi_norse);
    cout<<'\n';

    while(norse_gods){ //get to first element (no predecessor)
        if(!(norse_gods->previous())) break;
        norse_gods=norse_gods->previous();
    }
    while(norse_gods)
    {
        norse_gods = norse_gods->erase();
    }
    while(greek_gods){ //get to first element (no predecessor)
        if(!(greek_gods->previous())) break;
        greek_gods=greek_gods->previous();
    }
    while(greek_gods)
    {
        greek_gods = greek_gods->erase();
    }
}