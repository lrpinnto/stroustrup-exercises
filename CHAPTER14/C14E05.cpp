//CHAPTER 14 EX 05

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Striped_rectangle stre {{500,500},300,101};
    
    win.attach(stre);
    win.wait_for_button();
    stre.set_fill_color(Color::blue);
    win.wait_for_button();
    stre.set_color(Color::red);
    stre.set_style(Line_style(Line_style::dash,4));
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