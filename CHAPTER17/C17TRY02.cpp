//Chapter 17 Try this 02

#include <iostream>

using namespace std;

//simplified vector of doubles
class vector
{
private:
    int sz;
    double* elem;
public:
    vector(int s)
        :sz{s}, elem{new double[s]} //allocate s doubles on the freestore
    {
        cout<<"vector()\n";
        for (int i = 0; i < s; ++i) elem[i]=0;
    }
    int size() const { return sz; }
    ~vector()
    {
        cout<<"~vector()\n";
        delete[] elem;  // frees the memory for an array of objects allocated by new
    }
};

void f3(int n)
{
    double* p = new double[n]; // allocate n doubles
    cout<<"starting vector:\n";
    vector v(n);  //the vector allocates n doubles
    cout<<"deleting vector:\n";
    delete[] p; //deallocate p's doubles
}

class Base_class
{
private:
    
public:
    Base_class(/* args */)
    {
        cout<<"Base_class()\n";
    }
    virtual ~Base_class()
    {
        cout<<"~Base_class()\n";
    }
};

class Derived_class : public Base_class
{
private:

public:
    Derived_class(/* args */) 
    {
        cout<<"Derived_class()\n";
    }
    ~Derived_class() override
    {
        cout<<"~Derived_class()\n";
    }
};

Base_class* fct()
{
    cout<<"Calling fct()\n";
    cout<<"Creating Derived class dd:\n";
    Derived_class dd; //when dd goes out of scope, it is destroyed automatically by running the class internal (user defined or generated) destructors
    cout<<"Creating Base_class pointer:\n";
    Base_class* p = new Derived_class; //a Derived_class* can be implicitly converted to a Base_class* becasue Base_class is a public base of Derived_class
    
    cout<<"Exiting fct() and therefore, destroying Derived class dd\n";
    return p;
}

void f()
{
    cout<<"calling f()\n";
    Base_class* q = fct();
    cout<<"deleting Base_class pointer:\n";
    delete q; //frees the memory for an individual object allocated
    cout<<"done deleting Base_class pointer\n";
    cout<<"exiting f()\n";
}

int main()
{
    cout << "entering main()\n";
    cout<<"----------class stuff---------\n";
    f();
    cout<<"----------vector stuff--------\n";
    f3(5);
    cout << "leaving main()\n";
}

/*
int* p = nullptr;  // if you have no other pointer to use for initializing a pointer. use nullptr
delete p; // fine. despite not needing to be deleted, when can run this
delete p; // also fine. there is nothing to delete
*/
