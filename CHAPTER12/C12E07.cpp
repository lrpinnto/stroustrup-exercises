//CHAPTER 12 EX 07

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

//using namespace Graph_lib;

int main()
try
{
    Point tl {0,0};

    Simple_window small_win {tl,1600,900,"Window"}; 
    Rectangle Walls {Point{800,600},400,500};
    Polygon Roof;
    Roof.add(Point{600,350});
    Roof.add(Point{1000,350});
    Roof.add(Point{800,100});
    Roof.set_fill_color(Color::red);

    Rectangle win1 {Point{700,500},50,50};
    Rectangle win2 {Point{900,500},50,50};
    win1.set_fill_color(Color::blue);
    win2.set_fill_color(Color::blue);

    Function denominator {1/x,0,100,Point{700,550},1000,50,50};
    Function denominator2 {1/x,0,100,Point{900,550},1000,50,50};

    Rectangle door {Point{750,700},200,150};
    door.set_fill_color(Color::brown);

    Circle Handle {Point{850,700},10};
    handle.set_fill_color(Color::yellow);

    Rectangle floor {Point{0,850},1600,100};
    floor.set_fill_color(Color::green);

    win.attach(win1);
    win.attach(win2);
    win.attach(denominator);
    win.attach(denominator2);
    win.attach(door);
    win.attach(Handle);
    win.attach(floor);
    win.attach(Roof);
    win.attach(Walls);

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
