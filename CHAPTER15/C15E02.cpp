//CHAPTER 15 EX 02

#include "./sources.h"
#include <stdexcept>
//The exercise asks the reader to create a function called Fct but there's already a typedef called Fct defined on Graph.h. Naming it Fnct instead
struct Fnct : Function 
{
    Fnct(const Fct& ff, const double& r11, const double& r22, const Point& xyy, const int& countt, const double& xscalee, const double& yscalee)
    void set_range(int r11, int r22);
    void reset(//takes in constructor?);
    
private:
    Open_polyline op;
    double r1;
    double r2;
    Point xy;
    int count;
    double xscale;
    double yscale;
    Fct f;
    void construct_Fnct();
};

void Fnct::construct_Fnct()
{
    if (r2-r1<=0) error("bad graphing range");
	if (count<=0) error("non-positive graphing count");
	double dist = (r2-r1)/count;
	double r = r1;
	for (int i = 0; i<count; ++i) {
		op.add(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
		r += dist;
	}
}

Fnct::Fnct(const Fct& ff, const double& r11, const double& r22, const Point& xyy, const int& countt, const double& xscalee, const double& yscalee)
    : r1{r11}, r2{r22}, xy{xyy}, count{countt}, xscale{xscalee}, yscale{yscalee}, f{ff}
// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
// x coordinates are scaled by xscale and y coordinates scaled by yscale
{
	if (r2-r1<=0) error("bad graphing range");
	if (count<=0) error("non-positive graphing count");
	double dist = (r2-r1)/count;
	double r = r1;
	for (int i = 0; i<count; ++i) {
		op.add(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
		r += dist;
	}
}

int main()
try
{
    int win_x {600};
    int win_y {600};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Function graphs"}; 
    Axis x {Axis::Orientation::x,{100,300},400,20,"1==20 pixels"};
    Axis y {Axis::Orientation::y,{300,100},400,20,"1==20 pixels"};
    y.notches.set_color(Color::red);
    x.notches.set_color(Color::red);

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
