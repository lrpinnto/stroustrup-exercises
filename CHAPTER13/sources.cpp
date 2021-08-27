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

//EX 5 //Partially skipped for ellipse
Point center(Circle& circ)
{
    return circ.center();
}
Point s(Circle& circ)
{
    return {circ.center().x + circ.radius() * cos(PI / 2), circ.center().y + circ.radius() * sin(PI / 2)};
}
Point n(Circle& circ)
{
    return {circ.center().x + circ.radius() * cos(3* PI / 2), circ.center().y + circ.radius() * sin(3 * PI / 2)};
}
Point e(Circle& circ)
{
    return {circ.center().x + circ.radius() * cos(0), circ.center().y + circ.radius() * sin(0)};
}
Point w(Circle& circ)
{
    return {circ.center().x + circ.radius() * cos(PI), circ.center().y + circ.radius() * sin(PI)};
}
Point sw(Circle& circ)
{
    return {circ.center().x + circ.radius() * cos(3 * PI / 4), circ.center().y + circ.radius() * sin(3 * PI / 4)};
}
Point se(Circle& circ)
{
    return {circ.center().x + circ.radius() * cos(PI / 4), circ.center().y + circ.radius() * sin(PI / 4)};
}
Point nw(Circle& circ)
{
    return {circ.center().x + circ.radius() * cos(5 * PI / 4), circ.center().y + circ.radius() * sin(5 * PI / 4)};
}
Point ne(Circle& circ)
{
    return {circ.center().x + circ.radius() * cos(7 * PI / 4), circ.center().y + circ.radius() * sin(7 * PI / 4)};
}
//EX 5---

//EX 6
Box_text::Box_text(Point p, int lengthh, int widthh, int rr, const string& s)
    : Box{p,lengthh,widthh,rr}, t{p,s} {t.move(0,(lengthh/2)+t.font_size()/2);} //only attempts to center the text vertically

Box_text::Box_text(Point p, int rr, const string& s)
    : Box{p,10,10,rr}, t{p,s} //placeholder values
{
    t.move(5,t.font_size());            //any magic constants are trial and error in an attempt to fit the Text snuggly within the boxes walls
    Box::set_height(t.font_size()+4);
    Box::set_width((t.font_size()/1.7)*s.size());
}

void Box_text::set_label(const string& s, bool adjust_box) 
{ 
    t.set_label(s); 
    if(adjust_box)
    {
        Box::set_height(t.font_size()+4);
        Box::set_width((t.font_size()/1.7)*t.label().size()); 
    }
}

void Box_text::set_font_size(int s, bool adjust_box) { //if font size is set and adjust_box, change box accordingly
    t.set_font_size(s);
    if(adjust_box)
    {
        t.move(0,t.font_size()/2);
        Box::set_height(t.font_size()+4);
        Box::set_width((t.font_size()/1.7)*t.label().size()); 
    }
}

void Box_text::draw_lines() const
{
    Box::draw_lines();
    t.draw_lines();
}

Point n(Box_text& smth)
{
    return {smth.point(0).x+ smth.get_width()/2,smth.point(0).y};
}
Point s(Box_text& smth)
{
    return {smth.point(0).x+ smth.get_width()/2,smth.point(0).y+smth.get_height()};
}
//EX 6---

//EX 8
Regular_hexagon::Regular_hexagon(Point p, int r)
{
    const int N {6};
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i;
        add(Point{sin(radangle)*r+p.x,cos(radangle)*r+p.y});
    }
}

void Regular_hexagon::draw_lines() const
{
    Polygon::draw_lines();
}
//EX 8-----

//EX 10
Regular_polygon::Regular_polygon(Point p, int r, int N)
{
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i;
        add(Point{sin(radangle)*r+p.x,cos(radangle)*r+p.y});
    }
}

void Regular_polygon::draw_lines() const
{
    Polygon::draw_lines();
}
//EX 10---

//EX 14
Right_triangle::Right_triangle(Point p, int Horizontal_leg, int Vertical_leg, int anglee)
    : Hleg{Horizontal_leg}, Vleg{Vertical_leg}, angle{(PI/180)*anglee}
{
    Polygon::add(Point{cos(angle)*Hleg+p.x,sin(-angle)*Hleg+p.y});
    Polygon::add(Point{sin(angle)*Vleg+p.x,cos(angle)*Vleg+p.y});
    Polygon::add(p);
}

void Right_triangle::draw_lines() const
{
    Polygon::draw_lines();
}
//EX 14----

//EX 18
//Unable to import both functions. Taken from Graph.cpp
inline pair<double,double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel) 
{
    double x1 = p1.x;
    double x2 = p2.x;
	double x3 = p3.x;
	double x4 = p4.x;
	double y1 = p1.y;
	double y2 = p2.y;
	double y3 = p3.y;
	double y4 = p4.y;

	double denom = ((y4 - y3)*(x2-x1) - (x4-x3)*(y2-y1));
	if (denom == 0){
		parallel= true;
		return pair<double,double>(0,0);
	}
	parallel = false;
	return pair<double,double>( ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3))/denom,
								((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3))/denom);
}

bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection){
   bool parallel;
   pair<double,double> u = line_intersect(p1,p2,p3,p4,parallel);
   if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return false;
   intersection.x = p1.x + u.first*(p2.x - p1.x);
   intersection.y = p1.y + u.first*(p2.y - p1.y);
   return true;
} 

Poly::Poly(initializer_list<Point> lst)
{
    for (Point p : lst)
    {
        int np = number_of_points();
        if (1<np) 
        {	// check that thenew line isn't parallel to the previous one
            if (p==point(np-1)) error("polygon point equal to previous point");
            bool parallel;
            line_intersect(point(np-1),p,point(np-2),point(np-1),parallel);
            if (parallel)
                error("two polygon points lie in a straight line");
	    }

        for (int i = 1; i<np-1; ++i) 
        {	// check that new segment doesn't interset and old point
            Point ignore(0,0);
            if (line_segment_intersect(point(np-1),p,point(i-1),point(i),ignore))
                error("intersect in polygon");
        }
        Closed_polyline::add(p);
    }
}
//EX 18----

//EX 19
Star::Star(Point p, int R, int r, int N)
{
    if(N<4) error("not enough points to make a star");
    if(r<=0 || R<=0) error("negative radius on star");
    if(r>R) error("r cannot be bigger than R");
    else if(r==R) error("R and r need to be different");
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i + smallest_rad_division/2; //set phase "forward"
        add(Point{sin(radangle-smallest_rad_division/2)*r+p.x,cos(radangle-smallest_rad_division/2)*r+p.y});
        add(Point{sin(radangle)*R+p.x,cos(radangle)*R+p.y});   
    }
    block_add =true;  //terrible hack to avoid unwanted use of the add function
}

void Star::add(Point pp)
{
    if(block_add) error("add() cannot be used outside constructor on Star");
    Polygon::add(pp);
}
//EX 19----