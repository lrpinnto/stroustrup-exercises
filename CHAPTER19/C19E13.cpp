//Chapter 19 ex 13
//RESOURCE ACQUISITION IS INITIALIZATION

/*
Local objects
Member objects
Global objects
Objects allocated by new
...
*/

#include <iostream>
using namespace std;

class Tracer
{
private:
    string sc;
    string sd;
public:
    Tracer(string,string);
    ~Tracer();
    //COPY INIT AND DEF----
    Tracer(const Tracer& arg)
        :sc{arg.sc},sd{arg.sd} {cout<<"copy constructor: "<<sc<<'\n';}
    Tracer& operator=(const Tracer& a)
    {
        sc=a.sc;
        sd=a.sd;
        cout<<"copy assignment: "<<sc<<'\n';
        return *this;
    }
    //COPY INIT AND DEF----
};

struct s
{
    Tracer t {"Member","Member"};
};


Tracer::Tracer(string constructor, string destructor)
    :sc{constructor}, sd{destructor}
{
    cout<<"constructor: "<<sc<<'\n';
}

Tracer::~Tracer()
{
    cout<<"destructor: "<<sd<<'\n';
}

Tracer global_tr {"global","global"};

int main()
{
    cout << "BEGIN--------------main()\n";

    Tracer t1 {"main tracer", "main tracer"};

    s t2;

    Tracer* p {new Tracer{"new","new"}};

    delete p;

    Tracer t3 {t1};

    t1 = t3;

    cout << "END--------------main()\n";
}