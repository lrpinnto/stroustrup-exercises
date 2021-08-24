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

//EX 06
int mod(int x)
{
    if (x<0) return -1*x;
    else return x;
}

void Striped_circle::draw_lines() const
{
    if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
        fl_line_style(0,0); //Line_style affects this type of fill. Override it. these are default line values. Which we want for filling
        double angle;
        int horizontal_length;
        int opposite_leg;
		for (int i = Circle::center().y-Circle::radius(); i < Circle::center().y+Circle::radius(); i+=2)
        {
            //arc sin (Opposite leg / Hipotenuse) = angle (we know the opposite leg because we increment y from top to bottom)
            //Hipotenuse * cos (angle) = Horizontal length or adjacent leg
            opposite_leg = mod(Circle::center().y-i);
            angle = asin(opposite_leg/(Circle::radius()*1.0));
            horizontal_length = round(Circle::radius() * cos(angle));

            fl_line(Circle::center().x-horizontal_length,i,Circle::center().x+horizontal_length-1,i);
        }
		fl_color(color().as_int());	// reset color
        fl_line_style(Circle::style().style(),Circle::style().width()); //reset linestyle
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,Circle::radius()+Circle::radius(),Circle::radius()+Circle::radius(),0,360);
	}
}
//EX 06----