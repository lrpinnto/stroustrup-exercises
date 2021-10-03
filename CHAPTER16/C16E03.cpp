//CHAPTER 16 EX 03

#include "./sources.h" //need to create header files for this chapter

int main()
try
{
    Image_window win {Point{100,100},600,400,"EX 03"};
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