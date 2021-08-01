//CHAPTER 12 EX 08

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

//using namespace Graph_lib;

int main()
try
{
    Point tl {100,100};

    Simple_window win {tl,1600/3,900/3,"Window"}; 
    
    Image ii {Point{100,50},"image.jpg"};
    win.attach(ii);
    Text label {Point{100, 50}, "2 planes"};
    label.set_font(Graph_lib::Font::zapf_dingbats);
    label.set_font_size(20);
    win.attach(label);
    win.set_label("A random picture");

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
