//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' ../CHAPTER13/sources.cpp ../CHAPTER14/sources.cpp sources.cpp  C15EXX.cpp `fltk-config --ldflags --use-images` -o C15EXX

#include "./sources.h"

//Weird hack I had to come up with to allow Lambda expressions with capture within functions
//Use FunctionLambda instead of Function if your Function uses Lambda expressions
FunctionLambda::FunctionLambda(Fct2 f, double r1, double r2, Point xy, int count, double xscale, double yscale)
// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
// x coordinates are scaled by xscale and y coordinates scaled by yscale
{
	if (r2-r1<=0) error("bad graphing range");
	if (count<=0) error("non-positive graphing count");
	double dist = (r2-r1)/count;
	double r = r1;
	for (int i = 0; i<count; ++i) {
		add(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
		r += dist;
	}
}

//EX 02
void Fnct::construct_Fnct(Fct* ff, double r11, double r22, Point xyy, int countt , double xscalee , double yscalee )
{
    f=ff;
    r1=r11;
    r2=r22;
    xy=xyy;
    count= countt;
    xscale=xscalee; 
    yscale=yscalee;
    if (r2-r1<=0) error("bad graphing range");
	if (count<=0) error("non-positive graphing count"); 
	double dist = (r2-r1)/count;
	double r = r1;
    opv.clear();
	for (int i = 0; i<count; ++i) {
		opv.push_back(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
		r += dist;
	}
}

Fnct::Fnct(Fct* ff, double r11, double r22, Point xyy, int countt , double xscalee , double yscalee )
    : r1{r11}, r2{r22}, xy{xyy}, count{countt}, xscale{xscalee}, yscale{yscalee}, f{ff}
// graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed at xy
// x coordinates are scaled by xscale and y coordinates scaled by yscale
{
	if (r2-r1<=0) error("bad graphing range");
	if (count<=0) error("non-positive graphing count");
	double dist = (r2-r1)/count;
	double r = r1;
	for (int i = 0; i<count; ++i) {
		opv.push_back(Point(xy.x+int(r*xscale),xy.y-int(f(r)*yscale)));
		r += dist;
	}
}

void Fnct::draw_lines() const 
{    
    if (color().visibility())
        if (color().visibility() && 1<opv.size())	// draw sole pixel?
		for (unsigned int i=1; i<opv.size(); ++i)
			fl_line(opv[i-1].x,opv[i-1].y,opv[i].x,opv[i].y);
}
//EX 02---