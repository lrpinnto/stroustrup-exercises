#include <string>
#include <iostream>

class Tracer
{
private:
    std::string sc;
    std::string sd;
public:
    Tracer(std::string,std::string);
    ~Tracer();
    //COPY INIT AND DEF----
    Tracer(const Tracer& arg)
        :sc{arg.sc},sd{arg.sd} {std::cout<<"copy constructor: "<<sc<<'\n';}
    Tracer& operator=(const Tracer& a)
    {
        sc=a.sc;
        sd=a.sd;
        std::cout<<"copy assignment: "<<sc<<'\n';
        return *this;
    }
    //COPY INIT AND DEF----
};

Tracer::Tracer(std::string constructor, std::string destructor)
    :sc{constructor}, sd{destructor}
{
    std::cout<<"constructor: "<<sc<<'\n';
}

Tracer::~Tracer()
{
    std::cout<<"destructor: "<<sd<<'\n';
}