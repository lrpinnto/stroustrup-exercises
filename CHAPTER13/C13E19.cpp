//CHAPTER 13 EX 19
//ideally, Star shouldn't support add() function from polygon
//My solution is to overload add() to throw and error if used outside constructor

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    Star s {{500,500},200,100,5};
    win.attach(s);
    win.wait_for_button();
    s.set_fill_color(Color::red);
    win.wait_for_button();
    s.set_style(Line_style::dot);
    s.set_color(Color::cyan);
    win.wait_for_button();
    s.move(100,100);
    win.wait_for_button();
    s.add(Point{500,500});  //error throw test
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
