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
#include "./tracer.h"
using namespace std;

struct s
{
    Tracer t {"Member","Member"};
};

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