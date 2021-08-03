//CHAPTER 12 EX 07

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

//using namespace Graph_lib;

int main()
try
{
    Point tl {0,0};

    Simple_window win {tl,1600,900,"Window"}; 
    Rectangle Walls {Point{600,350},400,500};
    Polygon Roof;
    Roof.add(Point{600,350});
    Roof.add(Point{1000,350});
    Roof.add(Point{800,100});
    Roof.set_fill_color(Color::red);

    Rectangle win1 {Point{650,400},100,100};
    Rectangle win2 {Point{850,400},100,100};
    win1.set_fill_color(Color::blue);
    win2.set_fill_color(Color::blue);


    Rectangle door {Point{750,650},100,200};
    door.set_fill_color(Color::dark_red);

    Circle handle {Point{815,750},10};
    handle.set_fill_color(Color::yellow);

    Rectangle floor {Point{0,850},1700,100};
    floor.set_fill_color(Color::green);

    win.attach(win1);
    win.attach(win2);
    win.attach(door);
    win.attach(handle);
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
