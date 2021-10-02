//CHAPTER 16 EX 01

#include "./sources.h"

//Based on the book example and not on Simple_window.h for better understanding

int main()
try
{
    My_window win {Point{100,100},600,400,"Simple window"};
    Text test_text {{100,100},"Test Text"};
    win.attach(test_text);
    win.wait_for_button();
    Octagon oct {{100,100},100};
    win.attach(oct);
    win.set_label("label test");
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