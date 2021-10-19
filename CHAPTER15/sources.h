//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' ../CHAPTER13/sources.cpp ../CHAPTER14/sources.cpp sources.cpp  C15EXX.cpp `fltk-config --ldflags --use-images` -o C15EXX

#include "../CHAPTER14/sources.h"

//Weird hack I had to come up with to allow Lambda expressions with capture within functions
//Use FunctionLambda instead of Function if your Function uses Lambda expressions
typedef std::function<double (double)> Fct2; //Fix for C15E05.cpp see https://groups.google.com/g/ppp-public/c/WBHYlwS6m3g

struct FunctionLambda : Shape {
	// the function parameters are not stored
	FunctionLambda(Fct2 f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25);
	//Function(Point orig, Fct f, double r1, double r2, int count, double xscale = 1, double yscale = 1);	
};

//EX 02
//The exercise asks the reader to create a function called Fct but there's already a typedef called Fct defined on Graph.h. Naming it Fnct instead
struct Fnct : Shape 
{
    Fnct(Fct* ff, double r11, double r22, Point xyy, int countt = 100, double xscalee = 25, double yscalee = 25);

    void set_range(int r11, int r22) {construct_Fnct(f,r11,r22,xy,count,xscale,yscale);} 
    void set_scale(int xscalee,int yscalee) { construct_Fnct(f,r1,r2,xy,count,xscalee,yscalee); }
    void set_count(int countt){ construct_Fnct(f,r1,r2,xy,countt,xscale,yscale); }
    void move(int dx, int dy) { construct_Fnct(f,r1,r2,{xy.x+dx,xy.y+dy},count,xscale,yscale); }
    void set_func(Fct* ff) {construct_Fnct(ff,r1,r2,xy,count,xscale,yscale);}

    void draw_lines() const;
    
private:
    vector<Point> opv; //Couldn't use Open_polylines like I initial thought (Segmentation fault). Using points instead and using draw_lines() directly
    double r1;
    double r2;
    Point xy;
    int count;
    double xscale;
    double yscale;
    Fct* f;
    void construct_Fnct(Fct* ff, double r11, double r22, Point xyy, int countt = 100, double xscalee = 25, double yscalee = 25);
};
//EX 02----

//EX 03
template <int N>
struct Fnct_template : Shape 
{
    Fnct_template(Fct* ff, double r11, double r22, Point xyy, double xscalee = 25, double yscalee = 25)
        : r1{r11}, r2{r22}, xy{xyy}, count{N}, xscale{xscalee}, yscale{yscalee}, f{ff}
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

    void set_range(int r11, int r22) {construct_Fnct(f,r11,r22,xy,count,xscale,yscale);} 
    void set_scale(int xscalee,int yscalee) { construct_Fnct(f,r1,r2,xy,count,xscalee,yscalee); }
    void set_count(int countt){ construct_Fnct(f,r1,r2,xy,countt,xscale,yscale); }
    void move(int dx, int dy) { construct_Fnct(f,r1,r2,{xy.x+dx,xy.y+dy},count,xscale,yscale); }
    void set_func(Fct* ff) {construct_Fnct(ff,r1,r2,xy,count,xscale,yscale);}

    void draw_lines() const
    {    
    if (color().visibility())
        if (color().visibility() && 1<opv.size())	// draw sole pixel?
		for (unsigned int i=1; i<opv.size(); ++i)
			fl_line(opv[i-1].x,opv[i-1].y,opv[i].x,opv[i].y);
    }
    
private:
    vector<Point> opv; //Couldn't use Open_polylines like I initial thought (Segmentation fault). Using points instead and using draw_lines() directly
    double r1;
    double r2;
    Point xy;
    int count;
    double xscale;
    double yscale;
    Fct* f;
    void construct_Fnct(Fct* ff, double r11, double r22, Point xyy, int countt = 100, double xscalee = 25, double yscalee = 25)
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
};
//EX 03----

//EX 06 && 07
class Scale 
{
private:
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) :cbase{b}, vbase{vb}, scale{s} {}
    int operator()(int v) const {return cbase + (v-vbase)*scale; }
};

struct Bar_graph : Shape //Leave user to draw Axis independently
{
    Bar_graph(Point p, const vector<double>& data, int xlength, int ylength); //EX 06
    Bar_graph(Point p, const vector<double>& data, int xlength, int ylength, string label ,const vector<string>& labels, const vector<Color>& colors); //EX 07
    void draw_lines() const;
    void move(int dx, int dy) override;
private:
    Vector_ref<Rectangle> bars;
    Vector_ref<Text> bars_label;
    Vector_ref<Text> title;
    bool option_constr; //false if using basic constructor, true if using constructor with labels and colors
};
//EX 06 && 07 --