//CHAPTER 14 EX 11
//Need to finish behaviour from shape's functions (move(),set_color()...)
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