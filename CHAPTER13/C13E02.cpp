//CHAPTER 13 EX 02

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>
#include "./C13E01.cpp" //get Arc from last exercise

struct Box : Shape {
    Box(Point p, int lengthh, int widthh, int rr);

    void draw_lines() const;
private:
    int length; //y
    int width; //x //both widths and lengths need to match to make a box
    int r;
};

Box::Box(Point p, int lengthh, int widthh, int rr)
    : length{lengthh}, width{widthh}, r{rr}
{
    add(Point{p.x,p.y})
}

Box::draw_lines()
{
    vector<Point> points_length {
        {point(0).x,point(0).y+r},
        {point(0).x,point(0).y-r+length},
        {point(0).x+width,point(0).y+r},
        {point(0).x+width,point(0).y-r+length}
    };
    
    vector<Point> points_width {
        {point(0).x+r,point(0).y},
        {point(0).x-r+width,point(0).y+r},
        {point(0).x+r,point(0).y+length},
        {point(0).x-r+width,point(0).y+length},
    };

    //Arc for pi/2.  r is how rounded the box is

    if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,r+r-1,r+r-1,0,angle);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,r+r,r+r,0,angle);
	}
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
