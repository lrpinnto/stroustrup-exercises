//CHAPTER 13 EX 07
//Not too sure if this is the solution the author intended
#include "./sources.h"
#include <stdexcept>

int main()
try
{
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    Vector_ref<Rectangle> vr;
    Vector_ref<Text> tr;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            vr.push_back(new Rectangle{Point{i*20,j*20},20,20});
            tr.push_back(new Text{Point{i*20,j*20+14},to_string(i*16+j)});
            vr[vr.size()-1].set_fill_color(Color{i*16+j});
            win.attach(vr[vr.size()-1]);
            win.attach(tr[tr.size()-1]);
        }
    }
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