//CHAPTER 13 EX 12

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    int increment;

    cout<<"Please define smallest angle increment desired (in degrees):";
    cin>>increment;
    if(increment==0 || !cin) error("Please enter a valid number");


    cout<<"Please define radius:";
    int radius;
    cin>>radius;

    cout<<"Please enter amount of Points to be drawn";
    int N;
    cin>>N;

    Circle c {{win_x/2,win_y/2},radius};
    win.attach(c);
    double smallest_rad_division = increment*PI/180; //dividing full circle into N amount of points
    vector<Point> list; //make a list of all the calculated points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i;
        list.push_back(Point{sin(radangle)*radius+c.center().x,cos(radangle)*radius+c.center().y});
    }
    Vector_ref<Mark> markings;
    Vector_ref<Line> liness;
    for (Point p : list)
    {
        markings.push_back(new Mark{p,'X'});
        liness.push_back(new Line(c.center(),p));
        win.attach(markings[markings.size()-1]);
        win.attach(liness[liness.size()-1]);
        win.set_label(to_string(markings.size())+" points");
        win.wait_for_button();
    }
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