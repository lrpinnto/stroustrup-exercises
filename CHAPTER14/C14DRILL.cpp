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
    }                       //Step 5:
    virtual void pvf() =0;  //object of abstract class type "B1" is not allowed: -- function "B1::pvf" is a pure virtual function
};                          //object of abstract class type "D1" is not allowed: -- pure virtual function "B1::pvf" has no overrider

class D1 : public B1
{
private:

public:
    void vf() const override
    {
        cout<<"D1::vf()\n";
    }        //Step 4:
    void f() //Appears to override f() despite no virtual declaration on base class (B1)
    { 
        cout<<"D1::f()\n"; 
    }
};

class D2 : public D1
{
private:

public:
    void pvf() override
    {
        cout<<"D2::pvf()\n"; //Step 6: Can no longer invoke D1 or B1 due to pvf() remaining pure within D1 and B1. D2 works ok.
    }               
};

class B2
{
private:
    /* data */
public:
    virtual void pvf() =0;
};

class D21 : public B2  //I assume the author wants to inherit from B2. Not very specific in the book
{
private:
    string data {"D21::pvf()\n"};
public:
    
    void pvf() override
    {
        cout<<data;
    }
};

class D22 : public B2 //I assume the author wants to inherit from B2. Not very specific in the book
{
private:
    int data {22};
public:
    
    void pvf() override
    {
        cout<<data;
    }
};

void f(B2& b2)
{
    b2.pvf();
}

int main()
{
    /*B1 b1;
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
    b1_ref.f();*/
    cout<<"D2:\n";
    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();
    D21 d21;
    D22 d22;
    cout<<"f(d21):\n";
    f(d21);
    cout<<"f(d22):\n";
    f(d22);
}
