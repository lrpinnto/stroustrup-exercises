//CHAPTER 14 EX 03

#include <iostream>
using namespace std;

class Fruit
{
private:
    /* data */
public:
    virtual string color()=0; //Example of abstract class, pure virtual functions
protected: 
    Fruit(){}; //Example of abstract class. Constructor is protected.
};

class Strawberry : public Fruit
{
private:
    /* data */
public:
    using Fruit::Fruit;
    string color() override  //Explicit virtual function override. Ideal for large applications with complex hierarchies
    {
        return "test";
    }
};

int main()
try
{
    Strawberry st;
    cout<<st.color();
    //Fruit fr;                error: ‘Fruit::Fruit()’ is protected within this context
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
catch(...)
{
    // some more error reporting
    return 2;
}
