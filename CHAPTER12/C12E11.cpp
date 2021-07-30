//CHAPTER 12 EX 11

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>
#include <cmath>

//using namespace Graph_lib;

#define PI 3.14159265

int main()
try
{
    Point tl {0,0};
    Simple_window small_win {tl,1600,900,"Window"}; 

    //base triangle
    Polygon tri; //equilateral triangle
    poly.add{Point{1600/2-50,900}};
    poly.add{Point{1600/2+50,900}};
    poly.add{Point{1600/2,900-sin(60*PI/180)}} //opposite leg 

    win.attach(tri);

    vector<Point> current_points;
    current_points.push_back(Point{1600/2-50,900})
    current_points.push_back(Point{1600/2+50,900})
    current_points.push_back(Point{1600/2,900-sin(60*PI/180)});

    for (int i = 0; i < current_points.size()+1; i++) //for each set of current points, the new poligon will require N+1 points "prependicular" and centered to the opposing lines
    {
        //need an angle and the hipotenuse
        //with that I'll calculate the opposing and adjacent leg for each point
        //if the resulting point is outside of bounds, discard the value
        //the resulting polygon should always grow outwards of the base triangle and never go below it (so, outside of bounds)
    }
    
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
