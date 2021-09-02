//CHAPTER 14 EX 10

#include "./sources.h"
#include <stdexcept>

struct Pseudo_windown : Box
{
    Pseudo_window(Point p, int widthh, int heigthh, string labell);
    void set_label(string s ) {label = s;}
    string label() const {return label;}
    void draw_lines() const;
private:
    string label;
    //define extra widgets
};

Pseudo_window::Pseudo_window(Point p, int widthh, int heigthh, string labell)
    : Box(p,widthh,heigthh,10), label{labell}
{
    //declare Widgets
}

void draw_lines() const
{
    Box::draw_lines();
    //draw widgets
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    Pseudo_window ps {t1,win_x-100,win_y-100,"Pseudo Window"};
    win.attach(ps);
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
