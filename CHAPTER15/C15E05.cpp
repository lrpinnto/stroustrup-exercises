//CHAPTER 15 EX 05
//ADD ANIMATION
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

    double leibniz(int n)
    {
        if(n==0) return 1;
        return pow(-1,n)/(2*n+1)+leibniz(n-1)
    }

    //functions
    Function leibnizf { leibniz, -10, 11, {300,300},400,20,20 };
    cosine.set_color(Color::blue);
    win.attach(leibnizf);

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
