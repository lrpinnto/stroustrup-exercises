//CHAPTER 14 EX 9
//Unclear what functionality Group needs to have
#include "./sources.h"
#include <stdexcept>

struct Group {
    Group(){}
    Group(initializer_list<Point> lst);

    void add(Shape& s) { vr.push_back(s); }

    void move(int dx, int dy);
    void set_color(Color col);
    void set_fill_color(Color col);
    void set_style(Line_style sty);
private:
    Vector_ref<Shape> vr;
};

Group::Group(initializer_list<Shape> lst)
{
    for (Shape& s : lst)
    {
        add(s);
    } 
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

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
