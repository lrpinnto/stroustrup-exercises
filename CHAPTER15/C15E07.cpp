//CHAPTER 15 EX 07

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {600};
    int win_y {400};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Function graphs"}; 

    double highest_y {15};

    vector<double>as {1,2,3,2,6,1,8,highest_y,9,11,1,0,13};
    vector<string>lbls {"1","2","3","2","6","1","8","hy","9","11","1","0","13"};
    vector<Color>cls {Color::dark_blue,Color::dark_cyan,Color::dark_green,Color::dark_magenta,Color::dark_red,
                        Color::dark_yellow,Color::red,Color::blue,Color::dark_blue,Color::black,
                        Color::yellow,Color::green,Color::cyan};

    Point zero_center {200,350};
    int x_length {300};
    int y_length {300};

    Axis exe {Axis::x,zero_center,x_length,as.size(),"x"};
    exe.label.move(430,0); 
    Axis yi {Axis::y,zero_center,y_length,highest_y,"y"};

    Bar_graph br {zero_center,as,x_length,y_length,"Bar Graph",lbls,cls};
    win.attach(exe);
    win.attach(yi);
    win.attach(br);

    win.wait_for_button();
    exe.move(-50,-50);
    yi.move(-50,-50);
    br.move(-50,-50);
    win.set_label("move_test");
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