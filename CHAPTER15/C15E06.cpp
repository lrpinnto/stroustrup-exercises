//CHAPTER 15 EX 06

#include "./sources.h"
#include <stdexcept>

struct Bar_graph : Shape
{
    Bar_graph(Point p, const vector<double>& dataa)
    void draw_lines() const;
private:
    Vector_ref<Rectangle> bars;
    Axis x_axis;
    Axis y_axis;
};

Bar_graph::Bar_graph(Point p, const vector<double>& dataa)
{
    add(p); //is this really needed?
    //construct rectangles and Axis according to amount of information (perhaps, take input about size of axis?)
}

void Bar_graph::draw_lines() const
{
    x_axis.draw_lines();
    y_axis.draw_lines();
    for (int i = 0; i < bars.size(); i++)
    {
        bars[i].draw_lines();
    }
}

int main()
try
{
    int win_x {600};
    int win_y {600};
    Point tl {100,100};
    Graph_lib::Window win {tl,win_x,win_y,"Function graphs"}; 

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
