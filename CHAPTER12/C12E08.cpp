//CHAPTER 12 EX 08

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

//using namespace Graph_lib;

int main()
try
{
    Point tl {100,100};

    Simple_window win {tl,270,180,"Window"}; 

    int radius {30};
    int center_y {180/2-15};
    int center_x {270/2};
    //https://i.stack.imgur.com/1GJHS.jpg
    Circle center {Point{center_x,center_y},radius};
    Circle clu {Point{center_x-65,center_y},radius};
    Circle cld {Point{center_x-32.5,center_y+30},radius};
    Circle cru {Point{center_x+65,center_y},radius};
    Circle crd {Point{center_x+32.5,center_y+30},radius};
    center.set_style(Line_style(Line_style::solid,4));
    center.set_color(Color::black);
    clu.set_style(Line_style(Line_style::solid,4));
    clu.set_color(Color::blue);
    cld.set_style(Line_style(Line_style::solid,4));
    cld.set_color(Color::yellow);
    cru.set_style(Line_style(Line_style::solid,4));
    cru.set_color(Color::red);
    crd.set_style(Line_style(Line_style::solid,4));
    crd.set_color(Color::green);

    win.attach(center);
    win.attach(clu);
    win.attach(cld);
    win.attach(cru);
    win.attach(crd);

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
