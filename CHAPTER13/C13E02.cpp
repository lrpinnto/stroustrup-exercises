//CHAPTER 13 EX 02

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    Mark center {Point(100,100),'X'};
    Box h {Point(100,100),400,200,50};   //r is how rounded the box is
    win.attach(center);
    win.attach(h);
    win.wait_for_button();
    h.set_fill_color(Color::dark_yellow);
    win.wait_for_button();
    h.set_style(Line_style{Line_style::dash,4});
    win.wait_for_button();
    h.set_color(Color::blue);
    win.wait_for_button();
    h.move(100,100);
    win.wait_for_button();
    h.set_color(Color::invisible);
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
