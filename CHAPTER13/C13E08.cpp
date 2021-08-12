//CHAPTER 13 EX 08

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    Mark center {{300,300},'X'};
    Regular_hexagon rg {{300,300},40};
    win.attach(rg);
    win.attach(center);
    win.wait_for_button();
    rg.set_fill_color(Color::cyan);
    win.wait_for_button();
    rg.set_style(Line_style::dashdotdot);
    win.wait_for_button();
    rg.move(100,100);
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