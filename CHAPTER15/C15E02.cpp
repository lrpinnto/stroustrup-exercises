//CHAPTER 15 EX 02

#include "./sources.h"
#include <stdexcept>
//The exercise asks the reader to create a function called Fct but there's already a typedef called Fct defined on Graph.h. Naming it Fnct instead
struct Fnct : Function 
{
    Fnct(const Fct& f, const double& r11, const double& r22, const Point& xyy, const int& countt, const double& xscalee, const double& yscalee)
    void set_range(const Fct& f, int r11, int r22) {construct_Fnct(f,r11,r22,xy,count,xscale,yscale);} //is it possible to store Fct?
    void reset(const Fct& f, const double& r11, const double& r22, const Point& xyy, const int& countt, const double& xscalee, const double& yscalee); //everything from scratch
    void draw_lines() const;
    
private:
    vector<Open_polyline> opv; //Can it be Vector_ref or do we need to store a copy of every Open_polyline?
    double r1;
    double r2;
    Point xy;
    int count;
    double xscale;
    double yscale;
    //Fct f;
    void construct_Fnct(const Fct& f, const double& r11, const double& r22, const Point& xyy, const int& countt, const double& xscalee, const double& yscalee);
};

void Fnct::construct_Fnct(const Fct& f, const double& r11, const double& r22, const Point& xyy, const int& countt, const double& xscalee, const double& yscalee)
    : r1{r11}, r2{r22}, xy{xyy}, count{countt}, xscale{xscalee}, yscale{yscalee} //can it be used here? perhaps only on constructors?
{
    if (r2-r1<=0) error("bad graphing range");
	if (count<=0) error("non-positive graphing count");
    
	double dist = (r2-r1)/count;
	double r = r1;
    Open_polyline op;

	for (int i = 0; i<count; ++i) {

		op.add(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
		r += dist;
	}
    opv.pop_back(); //Clean up vector. maybe use clear() instead?
    opv.push_back(op)
}

Fnct::Fnct(const Fct& f, const double& r11, const double& r22, const Point& xyy, const int& countt, const double& xscalee, const double& yscalee)
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

void Fnct::draw_lines() const
{
    opv[opv.size()-1].draw_lines();
}

int main()
try
{
    constexpr int xmax {600};
    constexpr int ymax {600};

    constexpr int x_orig {xmax/2};
    constexpr int y_orig {ymax/2};
    const Point orig {x_orig,y_orig};

    constexpr int r_min {-10};
    constexpr int r_max {11};

    constexpr int n_points {400};

    constexpr int x_scale {20};
    constexpr int y_scale {20};

    constexpr int xlength {xmax-200}; //400
    constexpr int ylength {ymax-200}; //400

    Point tl {100,100};
    Graph_lib::Window win {tl,xmax,ymax,"Function graphs"}; 
    Axis x {Axis::Orientation::x,{orig.x-(xlength/2),orig.y},xlength,xlength/x_scale,"1==20 pixels"};
    Axis y {Axis::Orientation::y,{orig.x,orig.y+(ylength/2)},ylength,ylength/y_scale,"1==20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    x.label.set_color(Color::black);
    x.label.move(-30,0);
    y.label.set_color(Color::black);
    win.attach(x);
    win.attach(y);

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
