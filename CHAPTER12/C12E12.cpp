//CHAPTER 12 EX 12

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

vector<Point> get_points(int a, int b, int m, int n, int N)
{
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    vector<Point> list; //make a list of all the calculated points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i;
        list.push_back(Point{a*sin(radangle)^2/m,b*cos(radangle)^2/n});
    }
    return list;
}

int main()
try
{
    Point tl {0,0};
    Simple_window small_win {tl,1600,900,"Window"}; 
    int a,b,m,n,N;
    cout<<"Enter a,b,m,n,N where N is the superellipse resolution for |x/a|^m+|y/b|^n = 1. All ints separated by space: ";
    cin<<a<<b<<m<<n<<N;
    Closed_polyline poly_rect;
    for(Point p : get_points(a,b,m,n,N)) poly_rect.add(p);

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
