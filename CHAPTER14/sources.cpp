//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' ../CHAPTER13/sources.cpp sources.cpp  C14E01.cpp `fltk-config --ldflags --use-images` -o C14E01

#include "./sources.h"

//EX 05
void Striped_rectangle::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
        fl_color(fill_color().as_int());
        fl_line_style(0,0); //Line_style affects this type of fill. Override it. these are default line values. Which we want for filling
        for (int i = 2; i < Rectangle::height(); i+=2)
        {
            fl_line(Rectangle::point(0).x, Rectangle::point(0).y + i, Rectangle::point(0).x + Rectangle::width() -1, Rectangle::point(0).y + i);
        }
		fl_color(color().as_int());	// reset color
        fl_line_style(Rectangle::style().style(),Rectangle::style().width()); //reset linestyle
	}

	if (color().visibility()) {	// edge on top of fill
		fl_color(color().as_int());
		fl_rect(point(0).x,point(0).y,Rectangle::width(),Rectangle::height());
	}
}
//EX 05----