//CHAPTER 15 EX 06

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {600};
    int win_y {400};
    Point tl {100,100};
    Graph_lib::Window win {tl,win_x,win_y,"Function graphs"}; 

    double highest_y {15};

    vector<double>as {1,2,3,2,6,1,8,highest_y,9,11,1,0,13};

    Point zero_center {200,350};
    int x_length {300};
    int y_length {300};

    Axis exe {Axis::x,zero_center,x_length,as.size(),"x"};
    exe.label.move(430,0); 
    Axis yi {Axis::y,zero_center,y_length,highest_y,"y"};

    Bar_graph br {zero_center,as,x_length,y_length};
    win.attach(exe);
    win.attach(yi);
    win.attach(br);

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