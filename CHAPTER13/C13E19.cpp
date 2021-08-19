//CHAPTER 13 EX 19
//ideally, Star shouldn't support add() function from polygon
//My solution is to overload add() to throw and error if used outside constructor

#include "./sources.h"
#include <stdexcept>

struct Star : Polygon
{
    Star(Point p, int R, int r, int N); //R is radius or distance from center of the star to outside spikes. r is radius or distance from center of the start to inside spikes
    void add(Point pp);
private:
    bool block_add {false};
};

Star::Star(Point p, int R, int r, int N)
{
    if(N<4) error("not enough points to make a star");
    if(r<=0 || R<=0) error("negative radius on star");
    if(r>R) error("r cannot be bigger than R");
    else if(r==R) error("R and r need to be different");
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i + smallest_rad_division/2; //set phase "forward"
        add(Point{sin(radangle-smallest_rad_division/2)*r+p.x,cos(radangle-smallest_rad_division/2)*r+p.y});
        add(Point{sin(radangle)*R+p.x,cos(radangle)*R+p.y});   
    }
    block_add =true;  //terrible hack to avoid unwanted use of the add function
}

void Star::add(Point pp)
{
    if(block_add) error("add() cannot be used outside constructor on Star");
    Polygon::add(pp);
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    Star s {{500,500},200,100,5};
    win.attach(s);
    win.wait_for_button();
    s.set_fill_color(Color::red);
    win.wait_for_button();
    s.set_style(Line_style::dot);
    s.set_color(Color::cyan);
    win.wait_for_button();
    s.move(100,100);
    win.wait_for_button();
    s.add(Point{500,500});  //error throw test
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
