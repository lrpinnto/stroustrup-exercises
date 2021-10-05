//CHAPTER 16 EX 04

#include "./sources.h" 

int main()
try
{
    Shapes_window win {Point{100,100},600,400,"EX 04"};
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
