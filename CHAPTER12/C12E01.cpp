//CHAPTER 12 EX 01

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

using namespace Graph_lib;

int main()
try
{
    //An almost blank window
    Point tl {100,100};

    Simple_window win {tl,600,400,"Canvas"};

    //Polygons
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    poly.set_color(Color::red);
    win.attach(poly);
    win.set_label("Canvas #5");

    //Rectangles
    Rectangle r {Point{200,200},100,50};
    r.set_color(Color::blue);
    win.attach(r);
    win.set_label("Canvas #6");
    
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
