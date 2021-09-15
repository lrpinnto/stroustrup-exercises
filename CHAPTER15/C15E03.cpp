//CHAPTER 15 EX 03

#include "./sources.h"
#include <stdexcept>

template <class myType>
myType GetMax (myType a, myType b) {
 return (a>b?a:b);
}

int main()
try
{
    constexpr int xmax {600};
    constexpr int ymax {600};

    constexpr int x_orig {xmax/2};
    constexpr int y_orig {ymax/2};
    const Point orig {x_orig,y_orig};

    constexpr int r_min {-10};
    constexpr int r_max {11};

    constexpr int n_points {400};

    constexpr int x_scale {20};
    constexpr int y_scale {20};

    constexpr int xlength {xmax-200}; //400
    constexpr int ylength {ymax-200}; //400

    Point tl {100,100};
    Simple_window win {tl,xmax,ymax,"Function graphs"}; 
    Axis x {Axis::Orientation::x,{orig.x-(xlength/2),orig.y},xlength,xlength/x_scale,"1==20 pixels"};
    Axis y {Axis::Orientation::y,{orig.x,orig.y+(ylength/2)},ylength,ylength/y_scale,"1==20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    x.label.set_color(Color::black);
    x.label.move(-30,0);
    y.label.set_color(Color::black);
    win.attach(x);
    win.attach(y);

    Fnct one { [](double x)->double {return 1;},r_min,r_max,orig,n_points,x_scale,y_scale};
    one.set_color(Color::green);
    win.attach(one);
    win.set_label("Fnct constructor test");
    win.wait_for_button();
    win.detach(one);
    Function one_original { [](double x)->double {return 1;},r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(one_original);
    win.set_label("Orig comp test");
    win.wait_for_button();
    one.set_func([](double x)->double {return sin(x)+cos(x);});
    win.attach(one);
    win.set_label("Func reset tst");
    win.wait_for_button();
    win.detach(one_original);
    one.set_range(0,20);
    win.set_label("Range test");
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