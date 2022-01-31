//Chapter 19 ex 13
//Need to understand RAII notions to complete exercise
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

void f1()
{
    Tracer ft1 {"move assignment", "move assignment"};
    Tracer ft2 = ft1;
}

Tracer f2()
{
    Tracer ft3 {"move constructor", "move constructor"};
    return ft3;
}


Tracer global_tr {"global","global"};

int main()
{
    cout << "--------------main()\n";

    Tracer t1 {"main tracer", "main tracer"};

    f1();

    Tracer t2 = f2();

    Tracer t3 = t1;

    cout << "--------------main()\n";
}