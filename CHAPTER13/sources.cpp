//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' sources.cpp  C13E01.cpp `fltk-config --ldflags --use-images` -o C13E01
//use above command to compile on this chapter
#include "./sources.h"

//EX 1
Arc::Arc(Point p, int rr, double anglee, double angle_startt)  //treat as a circle
    : r{rr}, angle{anglee}, angle_start{angle_startt}, Ellipse(p,rr,rr) //When you declare a non-default constructor for a class, the compiler does not generate a default one anymore. So you have to provide your own.
{
	w=r;
	h=r;                                        //Since circle has no default constructor. It cannot be defined. I assume all inherited functions that are not overloaded work out of the definition of circle
    add(Point{ p.x - r, p.y - r });      //which should be fine as an arc is essentially a circle  
}

Arc::Arc(Point p, int ww, int hh, double anglee, double angle_startt)
	: w{ww}, h{hh}, angle{anglee}, angle_start{angle_startt}, Ellipse(p,ww,hh)
{
	add(Point{ p.x - ww, p.y - hh });
}
Arc::Arc(Point p, int ww, int hh, double anglee) : Arc(p,ww,hh,anglee,0) {}
Arc::Arc(Point p, int rr, double anglee) : Arc(p,rr,anglee,0) {}
void Arc::draw_lines() const  
{
    if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x,point(0).y,w+w-1,h+h-1,angle_start,angle);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x,point(0).y,w+w,h+h,angle_start,angle);
	}
}
//EX 1 -------

//EX 2
Box::Box(Point p, int lengthh, int widthh, int rr)
    : length{lengthh}, width{widthh}, r{rr}
{
    add(Point{p.x,p.y});
}

void Box::draw_lines() const
{
    vector<Point> points_length ;
    points_length.push_back({point(0).x,point(0).y+r});  //point(0) is the center
    points_length.push_back({point(0).x,point(0).y-r+length});
    points_length.push_back({point(0).x+width,point(0).y+r});
    points_length.push_back({point(0).x+width,point(0).y-r+length});
    
    vector<Point> points_width;
    points_width.push_back({point(0).x+r,point(0).y});
    points_width.push_back({point(0).x-r+width,point(0).y});
    points_width.push_back({point(0).x+r,point(0).y+length});
    points_width.push_back({point(0).x-r+width,point(0).y+length});


    if (fill_color().visibility()) {
        fl_color(fill_color().as_int()); //fill
        //draw fill rectangles
        fl_rectf(point(0).x+r,point(0).y+r,width-2*r,length-2*r);
        fl_rectf(point(0).x,point(0).y+r,r,length-2*r);
        fl_rectf(point(0).x+width-r,point(0).y+r,r,length-2*r);
        fl_rectf(point(0).x+r,point(0).y,width-2*r,r);
        fl_rectf(point(0).x+r,point(0).y+length-r,width-2*r,r);
        //draw fill circles
        fl_pie(point(0).x,point(0).y,r+r-1,r+r-1,0,360);
        fl_pie(point(0).x+width-2*r,point(0).y,r+r-1,r+r-1,0,360);
        fl_pie(point(0).x,point(0).y+length-2*r,r+r-1,r+r-1,0,360);
        fl_pie(point(0).x+width-2*r,point(0).y+length-2*r,r+r-1,r+r-1,0,360);
		fl_color(color().as_int());	// reset color
    }

    if (color().visibility()) //if outlines are set as visible, draw outlines
    {
        fl_color(color().as_int());
		for (int i=1; i<points_length.size(); i+=2)
        {
			fl_line(points_length[i-1].x,points_length[i-1].y,points_length[i].x,points_length[i].y);
            fl_line(points_width[i-1].x,points_width[i-1].y,points_width[i].x,points_width[i].y);
        }
    
        Point lu {point(0).x+r,point(0).y+r}; //left up
        Point ld {point(0).x+r,point(0).y+length-r}; //left down
        Point ru {point(0).x+width-r,point(0).y+r};
        Point rd {point(0).x+width-r,point(0).y+length-r};
        Arc Arc_lu {lu,r,180.0,90.0};   //Arcs are pi/2 angle to match each corner of the rectangle
        Arc Arc_ld {ld,r,270.0,180.0};
        Arc Arc_ru {ru,r,90.0};
        Arc Arc_rd {rd,r,360.0,270.0};
        Arc_lu.draw_lines();
        Arc_ld.draw_lines();
        Arc_ru.draw_lines();
        Arc_rd.draw_lines();
    }
}
//EX 2 ------