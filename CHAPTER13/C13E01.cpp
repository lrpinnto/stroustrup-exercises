//CHAPTER 13 EX 01
//Started doing the exercise and only then realised this needs to be done for an ellipse instead!
#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

struct Arc : Circle { //apparently, only inherits from public. Also, declaring objects with the same name as circle seems to overload them
    Arc(Point p, int rr, double anglee); //angle in degrees because of fl_arc
    
    void draw_lines() const;
    void set_angle(int anglee) { angle=anglee; }
private:
    int r;
    double angle;
};

Arc::Arc(Point p, int rr, double anglee)
    : r{rr}, angle{anglee}, Circle(p,rr) //When you declare a non-default constructor for a class, the compiler does not generate a default one anymore. So you have to provide your own.
{                                        //Since circle has no default constructor. It cannot be defined. I assume all inherited functions that are not overloaded work out of the definition of circle
    add(Point{ p.x - r, p.y - r });      //which should be fine as an arc is essentially a circle  
}
void Arc::draw_lines() const  
{
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
    Point tl {0,0};
    Simple_window win {tl,800,1000,"Window"}; 
    Arc something {Point{300,500},300,180};
    win.attach(something);
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
