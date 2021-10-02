//CHAPTER 16 EX 02

#include "./sources.h"

int main()
try
{
    Checkerboard_window win {Point{100,100},600,400,"EX 02"};
    win.wait_for_button();
}
catch(exception& e)
{
    std::cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr<<"Some exception\n";
    return 2;
}