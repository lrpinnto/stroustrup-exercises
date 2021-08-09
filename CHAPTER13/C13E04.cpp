//CHAPTER 13 EX 04

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    Rectangle r {Point{700,400},Point{1000, 875}};
    Vector_ref<Text> marking;
    marking.push_back(new Text{nw(r),"nw"});
    marking.push_back(new Text{n(r),"n"});
    marking.push_back(new Text{s(r),"s"});
    marking.push_back(new Text{e(r),"e"});
    marking.push_back(new Text{w(r),"w"});
    marking.push_back(new Text{center(r),"center"});
    marking.push_back(new Text{ne(r),"ne"});
    marking.push_back(new Text{se(r),"se"});
    marking.push_back(new Text{sw(r),"sw"});
    for (int i = 1; i<=marking.size(); i++)
    {
        win.attach(marking[marking.size()-i]);
        win.wait_for_button();
    }
    win.attach(r);
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