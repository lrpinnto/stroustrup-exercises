//CHAPTER 14 EX 10

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    Pseudo_window ps {tl,win_x-200,win_y-200,"Pseudo Window"};
    win.attach(ps);
    win.wait_for_button();
    ps.set_label("Test label");
    win.set_label("set_label()");
    win.wait_for_button();
    ps.set_height(100);
    win.wait_for_button();
    ps.set_width(100);
    win.wait_for_button();
    ps.set_width(500);
    win.wait_for_button();
    ps.set_height(win_y-200);
    ps.set_width(win_x-200);
    Circle ci {{300,300},100};
    Image im {{500,300},"image.jpg"};
    ps.attach(ci);  //ideally, would support some sort of clipping or maybe check that dimensions are within the Pseudo window
    ps.attach(im);
    win.set_label("attach() test");
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