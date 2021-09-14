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