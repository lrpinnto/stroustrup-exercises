//CHAPTER 15 DRILL

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {600};
    int win_y {600};
    Point tl {100,100};
    Graph_lib::Window win {tl,win_x,win_y,"Function graphs"}; 
    Axis x {Axis::Orientation::x,{100,300},400,20,"1==20 pixels"};
    Axis y {Axis::Orientation::y,{300,500},400,20,"1==20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    x.label.set_color(Color::black);
    x.label.move(-30,0);
    y.label.set_color(Color::black);
    win.attach(x);
    win.attach(y);
    /*
    Function one { [](double x)->double {return 1;},-10,11,{300,300},400}; 
    win.attach(one);
    */
    Function one { [](double x)->double {return 1;},-10,11,{300,300},400,20,20};
    win.attach(one);

    Function slope { [](double x)->double {return x/2;}, -10, 11, {300,300},400,20,20};
    win.attach(slope);
    Text slope_text {{300-(10*20),(300-(10*20))/2},"x/2"};
    win.attach(slope_text);

    Function square { [](double x)->double {return x*x;}, -10, 11, {300,300},400,20,20 };
    win.attach(square);

    Function cosine { cos, -10, 11, {300,300},400,20,20 };
    cosine.set_color(Color::blue);
    win.attach(cosine);

    Function sloping_cos { [](double x)->double {x/2 + cos(x);}, -10, 11, {300,300},400,20,20 };
    win.attach(sloping_cos);

    gui_main();
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