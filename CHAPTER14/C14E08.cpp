//CHAPTER 14 EX 08

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    //TESTING (are these the type of tests the author intended?)
    Octagon oct {{500,500},100,25};
    cout<</*oct.color()<<*/" "<</*oct.fill_color()<<*/"Number of points: "<<oct.number_of_points()<<"\n"<</*oct.style()<<*/"First Point drawn: "<<oct.point(0).x<<oct.point(0).y
        <<"\nCenter: "<<oct.center().x<<oct.center().y<<"\nradius: "<<oct.radius()<<"\nangle: "<<oct.angle();
    win.attach(oct);
    win.wait_for_button();
    oct.set_fill_color(Color::dark_green);
    oct.move(200,200);
    oct.set_color(Color::red);
    oct.set_style(Line_style(Line_style::dashdotdot,6));
    win.wait_for_button();
    //oct.add(); //set as protected on purpose. Is inaccessiable
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