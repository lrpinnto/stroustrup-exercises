//CHAPTER 13 EX 10

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    Vector_ref<Regular_polygon> vr;
    vr.push_back(new Regular_polygon{Point{win_x/2,win_y/2},300,3});
    win.attach(vr[0]);
    win.wait_for_button();
    for (int i = 4; i < 40; i++)
    {
        win.detach(vr[vr.size()-1]);
        vr.push_back(new Regular_polygon{Point{win_x/2,win_y/2},300,i});
        win.attach(vr[vr.size()-1]);
        win.set_label(to_string(i)+" sides");
        win.wait_for_button();
    }
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