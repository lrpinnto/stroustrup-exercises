//CHAPTER 12 EX 12
//Needs debugging
#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>
#include <cmath>

//using namespace Graph_lib;

constexpr double PI {3.14159265};

//how to get expressions:  https://fractional-calculus.com/super_ellipse.pdf
//http://www.cpp.re/forum/general/212070/
//parametric representation of an ellipse
//sin2(alfa)+cos2(alfa)=1  
//  |x/a|^m+|y/b|^n = 1   m,n >0  <=> x^m/a^m + y^n/b^n = 1
// sin2(rads) = x^m/a^m <=> x = asin(rads)^2/m , y = bcos(rads)^2/n (assuming positive x, y ,m,n)

vector<Point> get_points(double a, double b, double m, double n, int N)
{
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    vector<Point> list; //make a list of all the calculated points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i;
        list.push_back(Point{pow(a*sin(radangle),2/m),pow(b*cos(radangle),2/n)});
    }
    return list;
}

int main()
try
{
    Point tl {0,0};
    Simple_window win {tl,1600,900,"Window"}; 
    int center_x {1600/2};
    int center_y {900/2};
    double a,b,m,n;
    int N;
    cout<<"Enter a,b (more means a larger radius),m,n (more increases \"squariness\"),N where N is the superellipse resolution for |x/a|^m+|y/b|^n = 1. All ints separated by space: ";
    cin>>a>>b>>m>>n>>N;
    if ((a <= 0 || b <= 0) || (m <= 0 || n <= 0)) error("Positive args required.");
    //Axis
    Axis xa {Axis::x, Point{center_x,center_y},280,10,"x axis"}; //for some reason, the x axis label is set to move according to 
    xa.label.move(970,0); //fixes said issue
    win.attach(xa);                                               //the length of the axis divided by 3 unlike the y axis which moves
    win.set_label("Canvas #2");                                   //according to the Point coordinate. Probably a bug

    Axis ya {Axis::y, Point{center_x,center_y},280,10,"y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");

    Closed_polyline poly_rect;
    for(Point p : get_points(a,b,m,n,N)) poly_rect.add({p.x+center_x,p.y+center_y});

    win.attach(poly_rect);
    
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
