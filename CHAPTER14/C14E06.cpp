//CHAPTER 14 EX 06

#include "./sources.h"
#include <stdexcept>

struct Striped_circle : Circle
{
    using Circle::Circle;
    void draw_lines const;
};

void draw_lines() const
{
    if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
        double to_rad {PI/180};
        int previous_y {Circle::radius()*sin(90*to_rad)};
		for (int i = 0; i < 180; i++)
        {
            if(Circle::radius()*sin((90+i)*to_rad)-previous_y<=1) continue;  //checks for atleast 2 pixel difference
            previous_y = Circle::radius()*sin((90+i)*to_rad);
            fl_line(Circle::radius()*cos(90+i),previous_y,Circle::radius()*cos(90-i),previous_y);
        }
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
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
