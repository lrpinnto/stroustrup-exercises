//CHAPTER 15 DRILL

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {600};
    int win_y {600};
    Point tl {100,100};
    Window win {tl,win_x,win_y,"Function graphs"}; 
    Axis x {Axis::Orientation::x,{100,300},400,20,"1==20 pixels"};
    Axis y {Axis::Orientation::y,{300,100},400,20,"1==20 pixels"};
    y.notches.set_color(Color::red);
    x.notches.set_color(Color::red);

    Function one { [](double x)->double {return 1;},-10,11,{300,300},400};
    win.attach(one);
    Function one1 { [](double x)->double {return 1;},-10,11,{300,300},400,20,20};
    win.attach(one1);
    Function slope { [](double x)->double {return x/2;}, -10, 11, {300,300},400,20,20};
    win.attach(slope);
    Text slope_text {{100,500},"x/2"};
    win.attach(slope_text);
    Function square { [](double x)->double {return x*x;}, -10, 11, {300,300},400,20,20 };
    win.attach(square);
    Function cosine { cos, -10, 11, {300,300},400,20,20 };
    cosine.set_color(Color::blue);
    win.attach(cosine);
    Function sloping_cos { [](double x)->double {x/2 + cos(x);}, -10, 11, {300,300},400,20,20 };
    win.attach(sloping_cos);
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
