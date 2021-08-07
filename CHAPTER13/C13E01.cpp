//CHAPTER 13 EX 01

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    Arc something {Point{300,500},300,180};
    win.attach(something);
    win.label("Circle Arc");
    win.wait_for_button();
    Arc something2 {Point{500,500},400,200,-180};
    win.attach(something2);
    win.label("Ellipse Arc");
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
