//CHAPTER 12 EX 01 / 02 / 03 / 04

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

    Rectangle tic1 {Point{1180,280},10,620};
    Rectangle tic2 {Point{1390,280},10,620};
    Rectangle tic3 {Point{980,480},620,10};
    Rectangle tic4 {Point{980,690},620,10};
    tic1.set_fill_color(Color::black);
    tic2.set_fill_color(Color::black);
    tic3.set_fill_color(Color::black);
    tic4.set_fill_color(Color::black);
    win.attach(tic1);
    win.attach(tic2);
    win.attach(tic3);
    win.attach(tic4);
    win.set_label("Exercise 4");
    win.wait_for_button();

    Rectangle square1 {Point{990,290},180,180};
    square1.set_fill_color(Color::red);
    Rectangle square2 {Point{1200,290},180,180};
    Rectangle square3 {Point{990,500},180,180};
    Rectangle square4 {Point{1200,500},180,180};
    square4.set_fill_color(Color::red);
    Rectangle square5 {Point{990,710},180,180};
    square5.set_fill_color(Color::red);
    Rectangle square6 {Point{1200,710},180,180};
    Rectangle square7 {Point{1410,290},180,180};
    square7.set_fill_color(Color::red);
    Rectangle square8 {Point{1410,500},180,180};
    Rectangle square9 {Point{1410,710},180,180};
    square9.set_fill_color(Color::red);
    
    win.attach(square1);
    win.attach(square2);
    win.attach(square3);
    win.attach(square4);
    win.attach(square5);
    win.attach(square6);
    win.attach(square7);
    win.attach(square8);
    win.attach(square9);
    
    win.set_label("Exercise 4");

    win.wait_for_button();

    //assuming a 127 PPI (pixels per inch) so (1/4)127 = 31.75 aprox 32 pixels for 1/4 inch on my screen
    int fourth_inch {32};
    int line_style_offset {int(fourth_inch/2)}; //offset linestyle since it's drawn from the middle
    Rectangle inch {Point{50, 50}, line_style_offset + x_max() * 2 / 3 , line_style_offset +y_max() * 3 / 4};
    inch.set_style(Line_style(Line_style::solid, 32));
    inch.set_color(Color::red);
    win.attach(inch);
    win.set_label("Exercise 5");

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
