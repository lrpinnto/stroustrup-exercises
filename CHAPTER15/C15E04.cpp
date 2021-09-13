//CHAPTER 15 EX 04

#include "./sources.h"
#include <stdexcept>

//Functions don't seem to be properly aligned with the notches but that might just be some quirk with how FLTK works

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

    //functions
    Function sine { sin, r_min,r_max,orig,n_points,x_scale,y_scale};
    sine.set_color(Color::blue);
    win.attach(sine);

    Function cosine { cos, r_min,r_max,orig,n_points,x_scale,y_scale};
    cosine.set_color(Color::green);
    win.attach(cosine);

    Function sinecosine { [](double x)->double {return sin(x)+cos(x);},r_min,r_max,orig,n_points,x_scale,y_scale};
    sinecosine.set_color(Color::dark_yellow);
    win.attach(sinecosine);

    Function sinecosinesquare { [](double x)->double {return sin(x)*sin(x)+cos(x)*cos(x);}, r_min,r_max,orig,n_points,x_scale,y_scale};
    sinecosinesquare.set_color(Color::dark_cyan);
    win.attach(sinecosinesquare);

    //labels
    Text sinet {{orig.x-(r_min*x_scale),orig.y-(sin(r_min))*y_scale-1},"sin()"};
    sinet.set_color(Color::blue);
    Text cosinet {{orig.x-(r_min*x_scale),orig.y-(cos(r_min))*y_scale-1},"cos()"};
    cosinet.set_color(Color::green);
    Text sinecosinet {{orig.x-(r_min*x_scale),orig.y-(sin(r_min)+cos(r_min))*y_scale-1},"sin()+cos()"};
    sinecosinet.set_color(Color::dark_yellow);
    Text sinecosinesquaret {{orig.x-(r_min*x_scale),orig.y-(sin(r_min)*sin(r_min)+cos(r_min)*cos(r_min))*y_scale-1},"sin()*sin()+cos()*cos()"};
    sinecosinesquaret.set_color(Color::dark_cyan);
    win.attach(sinet);
    win.attach(cosinet);
    win.attach(sinecosinet);
    win.attach(sinecosinesquaret);

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