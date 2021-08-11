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
int Box::get_width() const {return width;}
int Box::get_height() const {return length;}
void Box::set_height(int h) {length=h;}
void Box::set_width(int w) {width=w;}
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

//EX 3
Arrow::Arrow(Point p1, Point p2)
    : Line(p1,p2), length{12}, adjustment_angle{20}
{
    //y = v * sin(α)
    //x = v * cos(α)
    //dividing both expressions:
    //y/x = v/v * sin(α)/cos(α) <=> y/x = tan(α)
    //atan(y/x) is held back some information and can only assume that the input came from quadrants I or IV. In contrast, atan2(y,x) gets all the data and thus can resolve the correct angle.
    angle = atan2(point(1).y - point(0).y, point(1).x - point(0).x)*180/PI; //difference between points gives the vector coordinates or slope
}

Arrow::Arrow(Point p1, Point p2, int lengthh, double anglee)
    : Line(p1,p2), length{lengthh}, adjustment_angle{anglee}
{
    angle = atan2(point(1).y - point(0).y, point(1).x - point(0).x)*180/PI;
}

void Arrow::draw_lines() const
{
    double x1 = point(1).x - cos((angle-adjustment_angle)*PI/180) * length;
    double y1 = point(1).y - sin((angle-adjustment_angle)*PI/180) * length;

    double x2 = point(1).x - cos((angle+adjustment_angle)*PI/180) * length;
    double y2 = point(1).y - sin((angle+adjustment_angle)*PI/180) * length;
    if (fill_color().visibility()) {
        fl_color(fill_color().as_int()); //fill
        fl_begin_complex_polygon();
			for(int i=0; i<3; ++i){ //fill arrowhead ONLY
				fl_vertex(point(1).x, point(1).y);
                fl_vertex(int(x1), int(y1));
                fl_vertex(int(x2), int(y2));
			}
		fl_end_complex_polygon();
        fl_color(color().as_int());	// reset color

    }
    if (color().visibility()) //if outlines are set as visible, draw outlines
    {
        fl_color(color().as_int());
        Lines arrow_lines;
        arrow_lines.add(point(1),Point{int(x1), int(y1)});
        arrow_lines.add(point(1),Point{int(x2), int(y2)});
        arrow_lines.draw_lines(); 
        Line::draw_lines();   
    }

}
//EX 3-----

//EX 4
Point nw(Rectangle& rect)
{
    return rect.point(0);
}
Point n(Rectangle& rect)
{
    //Rectangles are drawn from the nw and since rectangles dont take negative values. we can assume point(0) to be nw
    return {nw(rect).x + (rect.width()/2),nw(rect).y};
}
Point s(Rectangle& rect)
{
    return {nw(rect).x + (rect.width()/2), nw(rect).y + (rect.height())};
}
Point e(Rectangle& rect)
{
    return {nw(rect).x + rect.width(), nw(rect).y + (rect.height()/2)};
}
Point w(Rectangle& rect)
{
    return {nw(rect).x, nw(rect).y + (rect.height()/2)};
}
Point center(Rectangle& rect)
{
    return {nw(rect).x + (rect.width()/2), nw(rect).y + (rect.height()/2)};
}
Point ne(Rectangle& rect)
{
    return {nw(rect).x + rect.width(), nw(rect).y};
}
Point se(Rectangle& rect)
{
    return {nw(rect).x + rect.width(), nw(rect).y + rect.height()};
}
Point sw(Rectangle& rect)
{
    return {nw(rect).x , nw(rect).y + rect.height()};
}
//EX 4----

//EX 5
//SKIPPED
//EX 5---

//EX 6

//EX 6---