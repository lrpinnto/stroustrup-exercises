//CHAPTER 12 EX 01 / 02 /03

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

//using namespace Graph_lib;

int main()
try
{
    //An almost blank window
    Point tl {100,100};

    Simple_window win {tl,1600,900,"Canvas"};

    //Polygons
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    poly.set_color(Color::red);
    win.attach(poly);

    //Rectangles
    Rectangle r {Point{200,200},100,50};
    r.set_color(Color::blue);
    win.attach(r);
    win.set_label("Exercise 1");

    win.wait_for_button();

    Rectangle r2 {Point{600,400},100,30};
    win.attach(r2);

    Text t {Point{625,415}, "Howdy!"};
    win.attach(t);
    win.set_label("Exercise 2");
    
    win.wait_for_button();

    Text initial1 {Point{550, 350}, "L"};
    initial1.set_color(Color::dark_magenta);
    initial1.set_font_size(150);
    initial1.set_font(Graph_lib::Font::times_bold);

    Text initial2 {Point{650, 350}, "P"};
    initial2.set_color(Color::yellow);
    initial2.set_font_size(150);
    initial2.set_font(Graph_lib::Font::times_bold);
    
    win.attach(initial1);
    win.attach(initial2);
    win.set_label("Exercise 3");

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