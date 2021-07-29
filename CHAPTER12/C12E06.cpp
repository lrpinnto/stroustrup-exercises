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
    win.wait_for_button();
    Rectangle r {Point{200,200},600,600};
    win.attach(r);

    win.wait_for_button();
    //R:
    //--------------
    Point tl {100,100};

    Simple_window big_win {tl,2000,1100,"Big Window"}; //Assuming 1080p display
    //R:
    
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
