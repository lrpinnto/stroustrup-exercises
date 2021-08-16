//CHAPTER 13 EX 19

#include "./sources.h"
#include <stdexcept>

struct Star : Regular_polygon
{
    Star(Point p, int R, int r, int N); //R is radius or distance from center of the star to outside spikes. r is radius or distance from center of the start to inside spikes
};

Star::Star(Point p, int R, int r, int N)
    : Regular_polygon(p,R,N)
{
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i + smallest_rad_division/2; //set phase "forward"
        add(Point{sin(radangle)*r+p.x,cos(radangle)*r+p.y});
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
