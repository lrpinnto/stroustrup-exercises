//CHAPTER 13 EX 03

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    Axis ax {Axis::x,Point{1600/2,900/2},200,20,"X axis"};
    Axis ay {Axis::y,Point{1600/2,900/2},200,20,"Y axis"};
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    Arrow a {{1600/2,900/2},{1600/2+200,900/2-200}};
    Arrow b {{1600/2,900/2},{1600/2+200,900/2+200},50,40};
    Arrow c {{1600/2,900/2},{1600/2-200,900/2+200},40,170};
    Arrow d {{1600/2,900/2},{1600/2-200,900/2-200}};
    win.attach(ax);
    win.attach(ay);
    win.attach(a);
    win.attach(b);
    win.attach(c);
    win.attach(d);
    win.wait_for_button();
    c.set_fill_color(Color::black);
    a.set_fill_color(Color::blue);
    d.set_arrow_length(100);
    d.set_arrow_angle(80);
    b.set_color(Color::green);
    b.set_style(Line_style::dash);
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