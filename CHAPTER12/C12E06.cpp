//CHAPTER 12 EX 06

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

//using namespace Graph_lib;

int main()
try
{
    Point tl {100,100};

    Simple_window small_win {tl,400,400,"Small Window Big Shape"}; 
    small_win.wait_for_button();
    Rectangle r {Point{0,0},600,600};
    r.set_fill_color(Color::black);
    small_win.attach(r);
    small_win.set_label("Big Rectangle");
    small_win.wait_for_button();
    //R: Shape Takes over the display overlaying any other elements. In this case, the "Next" button. However, it's still interactive
    //--------------

    Simple_window big_win {tl,2000,1100,"Big Window"}; //Assuming 1080p display
    //R:Window takes over the whole display while the with the window controls "growing" out of the display's range
    
    big_win.wait_for_button();
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
