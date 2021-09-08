//CHAPTER 15 EX 04

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

    //functions
    Function sine { sin, -10, 11, {300,300},400,20,20 };
    cosine.set_color(Color::blue);
    win.attach(sine);

    Function cosine { cos, -10, 11, {300,300},400,20,20 };
    cosine.set_color(Color::green);
    win.attach(cosine);

    Function sinecosine { [](double x)->double {return sin(x)+cos(x)} , -10, 11, {300,300},400,20,20 };
    cosine.set_color(Color::dark_yellow);
    win.attach(sinecosine);

    Function sinecosinesquare { [](double x)->double {return sin(x)*sin(x)+cos(x)*cos(x)} , -10, 11, {300,300},400,20,20 };
    cosine.set_color(Color::dark_cyan);
    win.attach(sinecosinesquare);

    //labels
    Text sinet {{300-(10*20),y_point},"sin()"};
    Text cosinet {{300-(10*20),y_point},"cos()"};
    Text sinecosinet {{300-(10*20),y_point},"sin()+cos()"};
    Text sinecosinesquaret {{300-(10*20),y_point},"sin()*sin()+cos()*cos()"};
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
