//CHAPTER 12 EX 12
//Skipped for now
#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>
#include <cmath>

//using namespace Graph_lib;

constexpr PI {3.14159265};

//how to get expressions:  https://fractional-calculus.com/super_ellipse.pdf
//http://www.cpp.re/forum/general/212070/
//sin2(x)+cos2(x)=1  (circle)
//x = 2 π n + π, n element Z solution
//  |x/a|^m+|y/b|^n = 1   m,n >0  <=> |x/a|^m = 1 - |y/b|^n <=> |x/a| = mroot(1 - |y/b|^n) <=> x = mroot(1 - |y/b|^n) * a

vector<Point> get_points(int a, int b, int m, int n, int N)
{
    double p = 2*PI/N; //dividing full circle into N amount of points

    for (int i = 0; i < N; i++)
    {
        double t = p * i;


    }
    
    

}

int main()
try
{
    Point tl {0,0};
    Simple_window small_win {tl,1600,900,"Window"}; 
    
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
