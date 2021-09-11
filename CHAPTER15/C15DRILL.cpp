//CHAPTER 15 DRILL

#include "./sources.h"
#include <stdexcept>

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

    constexpr int xlength {xmax-200};
    constexpr int ylength {ymax-200};

    Point tl {100,100};
    Graph_lib::Window win {tl,xmax,ymax,"Function graphs"}; 
    Axis x {Axis::Orientation::x,{orig.x-(xlength/2),orig.y},xlength,xlength/x_scale,"1==20 pixels"};
    Axis y {Axis::Orientation::y,{orig.x,orig.y+(ylength/2)},ylength,ylength/y_scale,"1==20 pixels"};
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
    Function one { [](double x)->double {return 1;},r_min,r_max,orig,n_points,x_scale,y_scale};
    win.attach(one);

    Function slope { [](double x)->double {return x/2;}, r_min, r_max, orig,n_points,x_scale,y_scale};
    win.attach(slope);
    Text slope_text {{orig.x+(r_min*x_scale) ,orig.y-(r_min/2)*y_scale-1},"x/2"}; //"at a point just above its bottom left end point." Therefore I used -1
    win.attach(slope_text);

    Function square { [](double x)->double {return x*x;}, r_min, r_max, orig,n_points,x_scale,y_scale };
    win.attach(square);

    Function cosine { cos, r_min, r_max, orig,n_points,x_scale,y_scale };
    cosine.set_color(Color::blue);
    win.attach(cosine);

    Function sloping_cos { [](double x)->double {return x/2 + cos(x);}, r_min, r_max, orig,n_points,x_scale,y_scale };
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