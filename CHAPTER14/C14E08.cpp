//CHAPTER 14 EX 08

#include "./sources.h"
#include <stdexcept>

struct Octagon : Polygon
{
    Octagon(Point p, int r);
    void draw_lines() const;
};

Octagon::Octagon(Point p, int r)
{
    const int N {8};
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i;
        add(Point{sin(radangle)*r+p.x,cos(radangle)*r+p.y});
    }
}

void Octagon::draw_lines() const
{
    Polygon::draw_lines();
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    //write tests to all functions from Octagon
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
