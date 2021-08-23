//CHAPTER 14 EX 04

#include "./sources.h"
#include <stdexcept>
//Delete virtual function from a derived class
/*The best solution I have found so far to get a compile-time error when calling Ds method is by using a static_assert with a generic struct that inherits from false_type. 
As long as noone ever calls the method, the struct stays undefied and the static_assert won't fail.

If the method is called however, the struct is defined and its value is false, so the static_assert fails.

If the method is not called, but you try to call it on a pointer of the super class, then Ds method is not defined and you get an undefined reference compilation error.*/
//Reference: https://stackoverflow.com/questions/24609872/delete-virtual-function-from-a-derived-class

struct Immobile_Circle : Circle
{
    using Circle::Circle;
private:
    using Circle::move;  //The first would be to use using to change the visibility of the method to private, thus preventing others from using it. 
};                         //The problem with that solution is, that calling the method on a pointer of the super-class does not result in a compilation error.

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Immobile_Circle ic {{100,100},100};
    ic.move(100,100); //Should be inaccessible

    win.attach(ic);
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
