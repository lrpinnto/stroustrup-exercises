//CHAPTER 14 DRILL

#include <iostream>
using namespace std;

class B1
{
private:
    
public:
    virtual void vf() const
    {
        cout<<"B1::vf()\n";
    }
    void f() const
    {
        cout<<"B1::f()\n";
    }
};

class D1 : public B1
{
private:

public:
    void vf() const override
    {
        cout<<"D1::vf()\n";
    }
    void f() //Appears to override f() despite no virtual declaration on base class (B1)
    { 
        cout<<"D1::f()\n"; 
    }
};

int main()
{
    B1 b1;
    cout<<"b1:\n";
    b1.vf();
    b1.f();
    D1 d1;
    cout<<"d1:\n";
    d1.vf();
    d1.f();
    B1& b1_ref {d1};
    cout<<"b1_ref:\n";
    b1_ref.vf();
    b1_ref.f();
}
