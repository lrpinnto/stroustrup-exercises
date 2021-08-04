//CHAPTER 12 EX 11
//Need to add a way to align the figures properly and have an increased radius between figures
#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>
#include <cmath>

//using namespace Graph_lib;

constexpr double PI {3.14159265};

struct special_poly : Polygon { //Explained later in chapter 13. Found no alternative to using this
    using Polygon::Polygon;     // Essentially means, special_poly is a type of Polygon
    special_poly(vector<Point>&points) //Created so I can initialize with a list on vr.push_back(new special_poly{points});
    {
        for (Point p : points)
        {
            Polygon::add(p);
        }
        
    }
};

vector<Point> get_points(int N)
{
    int radius {100};
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    vector<Point> list; //make a list of all the calculated points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i;
        list.push_back(Point{sin(radangle)*radius,cos(radangle)*radius});
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
    Vector_ref<Polygon> vr; //This is taught later on in the book (chapter 13 page 467) but I found no alternatives besides doing
    for(int N = 3; N<10;N++)  //everything manually (which I think defeats the purpose)
    {
        vector<Point>points;
        for(Point p : get_points(N))
        {
            points.push_back({p.x+center_x,p.y+center_y});
        }
        vr.push_back(new special_poly{points});
        win.attach(vr[vr.size()-1]);
        win.set_label(to_string(N)+" angles");
        win.wait_for_button();
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