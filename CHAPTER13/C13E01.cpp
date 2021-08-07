//CHAPTER 13 EX 01
//Started doing the exercise and only then realised this needs to be done for an ellipse instead!
#include "./sources.h"
#include <stdexcept>

int main()
try
{
    Point tl {0,0};
    Simple_window win {tl,800,1000,"Window"}; 
    Arc something {Point{300,500},300,180};
    win.attach(something);
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
