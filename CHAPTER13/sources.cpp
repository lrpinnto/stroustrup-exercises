//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' sources.cpp  C13E01.cpp `fltk-config --ldflags --use-images` -o C13E01
//use above command to compile on this chapter
#include "./sources.h"

//EX 1
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
//EX 1 -------