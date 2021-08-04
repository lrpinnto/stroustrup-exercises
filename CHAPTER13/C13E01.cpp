//CHAPTER 13 EX 01

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

Struct Arc : Shape {
    Arc(Point p, int rr, double angle) //angle in rads

    void draw_lines() const;

    Point center() const;
    int radius() const { return r;}
    void set_radius(int rr)
    {
        set_point(0,Point{center().x-rr,center().y-rr});

        r=rr;
    }
private:
    int r;
};

Arc::Arc(Point p, int rr, double angle)
    :r{rr}
{
    add(Point{p.x-r,p.y-r});
}

int main()
try
{

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
