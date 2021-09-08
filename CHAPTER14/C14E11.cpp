//CHAPTER 14 EX 11

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    Vector_ref<Binary_tree> bt;
    for (int i = 0; i < 10; i++)
    {
        win.set_label("level "+to_string(i));
        bt.push_back(new Binary_tree{i});
        win.attach(bt[bt.size()-1]);
        win.wait_for_button();
        win.detach(bt[bt.size()-1]);
    }

    win.attach(bt[3]);
    win.wait_for_button();
    bt[3].move(100,100);
    win.wait_for_button();
    bt[3].set_fill_color(Color::dark_yellow);
    win.wait_for_button();
    bt[3].set_style(Line_style(Line_style::dashdot, 30)); //doesn't work
    bt[3].set_color(Color::dark_red);
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