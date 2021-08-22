//CHAPTER 14 EX 02

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Circle c {{100,100},100}; //Circle, a shape
    Circle c2 {c}; //error: use of deleted function ‘Graph_lib::Circle::Circle(const Graph_lib::Circle&)’

    Polygon p;  //Polygon, a shape with a default constructor;
    Polygon p2;
    p=p2; //error: use of deleted function ‘Graph_lib::Polygon& Graph_lib::Polygon::operator=(const Graph_lib::Polygon&)’

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
