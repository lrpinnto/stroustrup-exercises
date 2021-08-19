//CHAPTER 13 EX 18
//I believe the Polygon check is done intrinsically within Polygon::add(). No need to have another check inside the constructor?
#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    list<Point>good_poly_list {{100,100},{100,200},{200,200},{200,100}};
    list<Point>bad_poly_list {{100,100},{100,200},{200,200},{200,100},{150,150}};
    Poly good_poly {{100,100},{100,200},{200,200}};
    Polygon pp;
    pp.add({100,100});
    pp.add({100,200});
    pp.add({200,200});
    win.attach(pp);
    pp.move(100,100);
    win.attach(good_poly);
    win.wait_for_button(); //should throw an error after this button
    Poly bad_poly {{100,100},{100,200},{200,200},{200,100},{150,250}};
    win.attach(bad_poly);
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
