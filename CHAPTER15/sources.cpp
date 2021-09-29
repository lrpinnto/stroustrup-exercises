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

//EX 06 && 07
Bar_graph::Bar_graph(Point p, const vector<double>& data, int xlength, int ylength) //EX 06 
    :option_constr{false}
{
    double ceil_value {data[0]};
    //double floor_value {data[0]};
    for(double h : data)
    {
        if(h>ceil_value) ceil_value=h;
        //if(h<floor_value) floor_value=h;
    }
    double xscale = double(xlength)/(data.size()); 
    double yscale = double(ylength)/ceil_value;
    Scale xs {p.x,0,xscale};
    Scale ys {p.y,0,-yscale};

    int spacing {(xs(1)-p.x)/2}; //"radius" between bars
    for (int i = 0; i < data.size(); i++)
    {
        if(data[i]==0) continue; //no such thing as a 0 length rectangle
        bars.push_back(new Rectangle{Point{xs(i+1)-spacing,ys(data[i])},Point{xs(i+1)+spacing,p.y}});
    }
}

Bar_graph::Bar_graph(Point p, const vector<double>& data, int xlength, int ylength, string label ,const vector<string>& labels, const vector<Color>& colors) //EX 07 
    :option_constr{true}
{
    if (labels.size()!=data.size() || colors.size()!= data.size()) error("Bar_graph: Vectors need to match in size");
    double ceil_value {data[0]};
    //double floor_value {data[0]};
    for(double h : data)
    {
        if(h>ceil_value) ceil_value=h;
        //if(h<floor_value) floor_value=h;
    }
    double xscale = double(xlength)/(data.size()); 
    double yscale = double(ylength)/ceil_value;
    Scale xs {p.x,0,xscale};
    Scale ys {p.y,0,-yscale};

    int spacing {(xs(1)-p.x)/2}; //"radius" between bars
    int ignore_count {0}; //weird hack to account for "skipped indexes"
    for (int i = 0; i < data.size(); i++)
    {
        bars_label.push_back(new Text{Point{xs(i+1)-spacing,p.y+20},labels[i]});
        if(data[i]==0) {ignore_count++;continue;} //no such thing as a 0 length rectangle
        bars.push_back(new Rectangle{Point{xs(i+1)-spacing,ys(data[i])},Point{xs(i+1)+spacing,p.y}});
        bars[i-ignore_count].set_fill_color(colors[i]);
    }
    title.push_back(new Text{Point{xs(bars.size()/2),ys(ceil_value)-20},label});
}

void Bar_graph::draw_lines() const
{
    if(option_constr)
    {
        title[0].draw_lines();
        for (int i = 0; i < bars_label.size(); i++)
        {
            bars_label[i].draw_lines();
        }
    }
    for (int i = 0; i < bars.size(); i++)
    {
        bars[i].draw_lines();
    }
}
void Bar_graph::move(int dx, int dy)
{
    if(option_constr)
    {
        title[0].move(dx,dy);
        for (int i = 0; i < bars_label.size(); i++)
        {
            bars_label[i].move(dx,dy);
        }
    }
    for (int i = 0; i < bars.size(); i++)
    {
        bars[i].move(dx,dy);
    }
}
//EX 06 && 07--