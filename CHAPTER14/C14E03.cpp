//CHAPTER 14 EX 03

#include "./sources.h"
#include <stdexcept>

class Fruit
{
private:
    /* data */
public:
    virtual string color()=0 //Example of abstract class, pure virtual functions
protected: //Example of abstract class
    Fruit(){};
    int mass();
    int volume();
};

class Strawberry : public Fruit
{
private:
    /* data */
public:
    using Fruit::Fruit;
    int mass() override
    {
        return 1;
    }
    int volume() override
    {
        return 1;
    }
    string color() override
    {
        return "test";
    }
};

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    Strawberry st;
    win.wait_for_button();
    Fruit fr; //should throw error
    win.wait_for_button();
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
