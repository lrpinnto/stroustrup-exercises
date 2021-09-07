//CHAPTER 14 EX 07

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Striped_closed_polyline stri;
    stri.add({100,100});  //make weird polyline
    stri.add({50,200});
    stri.add({100,300});
    stri.add({170,280});
    stri.add({200,180});
    stri.add({150,200});
    stri.set_fill_color(Color::blue);
    win.attach(stri);
    win.wait_for_button();
    stri.set_color(Color::red);
    stri.set_style(Line_style(Line_style::dashdot,10));
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