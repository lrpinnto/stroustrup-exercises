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

//EX 07
// does two lines (p1,p2) and (p3,p4) intersect?
// if se return the distance of the intersect point as distances from p1
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


//intersection between two line segments
//Returns true if the two segments intersect,
//in which case intersection is set to the point of intersection
inline bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection){
   bool parallel;
   pair<double,double> u = line_intersect(p1,p2,p3,p4,parallel);
   if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return false;
   intersection.x = p1.x + u.first*(p2.x - p1.x);
   intersection.y = p1.y + u.first*(p2.y - p1.y);
   return true;
} 
void Striped_closed_polyline::draw_lines() const
{
    //Create limiting square/rectangle
    int x_min {point(0).x};
    int x_max {0};
    int y_min {point(0).y};
    int y_max {0};
    for (int i = 0; i < number_of_points(); i++)
    {
        if(point(i).x<x_min) x_min=point(i).x;
        if(point(i).y<y_min) y_min=point(i).y;
        if(point(i).x>x_max) x_max=point(i).x;
        if(point(i).y>y_max) y_max=point(i).y;
    }
    if (fill_color().visibility()) {	// fill
        fl_color(fill_color().as_int());
        fl_line_style(0,0); //Line_style affects this type of fill. Override it. these are default line values. Which we want for filling
        //check for intersects, one line at the time. get the list of intersection points and draw lines accordingly
        //do this every 2 vertical lines
        Point intersection;
        vector<Point>intersections;
        for (int i = y_min + 2; i < y_max; i+=2)
        {
            //check which pairs of points intersect then y axis on the given i (doing this out of efficency, maybe it's not the best way?)
            vector<pair<Point,Point>> pairs_of_points;              //A vector of pairs of points. In this context, that intersect the given i or y axis 
            if (point(number_of_points()-1).y < i && i <= point(0).y || point(0).y < i && i <= point(number_of_points()-1).y )   //do last pair, first
            {
                pairs_of_points.push_back({point(number_of_points()-1),point(0)});
            }
            for (int index = 0; index < number_of_points()-1; index++)
            {
                if( point(index).y < i && i <= point(index +1 ).y || point(index+1).y < i && i <= point(index ).y ) 
                {
                    pairs_of_points.push_back({point(index),point(index+1)});
                }
            }

            if(pairs_of_points.size()==1) pairs_of_points.clear();
            

            for(pair<Point,Point> point_pair : pairs_of_points)
            {
                if(line_segment_intersect(Point(point_pair.first.x,i),Point(point_pair.second.x,i),point_pair.first,point_pair.second,intersection))
                    intersections.push_back(intersection); 
            }
            pairs_of_points.clear();

            for (int index = 0; index < intersections.size(); index+=2)
            {
                fl_line(intersections[index].x,intersections[index].y,intersections[index+1].x,intersections[index+1].y);
            }

            intersections.clear();
        }
        fl_color(color().as_int());	// reset color
        fl_line_style(Closed_polyline::style().style(),Closed_polyline::style().width()); //reset linestyle
    }
    if (color().visibility())
        Shape::draw_lines(); //need to use Shape's draw in order to avoid the Closed_polyline filling the shape
        fl_line(point(number_of_points()-1).x,point(number_of_points()-1).y,point(0).x,point(0).y);// draw closing line:
}
//EX 07----

//EX 08
Octagon::Octagon(Point p, int rr, int anglee)  //anglee in degrees
    : r{rr}, ref_angle{anglee*PI/180.0}, center_point(p)
{
    if(r<2) error("small radius on Octagon()"); //find minimum radius that forms a Octagon
    const int N {8};
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i + ref_angle;
        Polygon::add(Point{sin(radangle)*r+p.x,cos(radangle)*r+p.y});
    }
}

void Octagon::draw_lines() const
{
    Polygon::draw_lines();
}
//EX 08----

//EX 09
Group::Group(Vector_ref<Shape>&sp)
{
    for (int i = 0; i < sp.size(); i++)
    {
        add(sp[i]);
    }
}

void Group::draw_lines() const
{
    for (int i = 0; i < vr.size(); i++)
    {
        vr[i].draw();
    }
}

void Group::set_color(Color col)
{
    for (int i = 0; i < vr.size(); i++)
    {
        vr[i].set_color(col);
    }
}

void Group::set_fill_color(Color col)
{
    for (int i = 0; i < vr.size(); i++)
    {
        vr[i].set_fill_color(col);
    }
}

void Group::set_style(Line_style sty)
{
    for (int i = 0; i < vr.size() ; i++)
    {
        vr[i].set_style(sty);
    }
}

void Group::move(int dx, int dy)
{
    for (int i = 0; i < vr.size(); i++)
    {
        vr[i].move(dx,dy);
    }
}

void Group::move(int dx, int dy, int index) {vr[index].move(dx,dy);}
//EX 09----

//EX 10
void Resizeable_rectangle::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_rectf(point(0).x,point(0).y,w,h);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {	// edge on top of fill
		fl_color(color().as_int());
		fl_rect(point(0).x,point(0).y,w,h);
	}
}

Pseudo_window::Pseudo_window(Point p, int widthh, int heigthh, string labell)
    : Box(p,heigthh,widthh,10), label_text{labell}, top_bar{p,30,widthh,10}, top_bar2{{p.x,p.y+15},widthh,20}, 
    exit_sym{{p.x+widthh-18,p.y+23},"X"}, text_top{{p.x+widthh/2,p.y+19},label_text}, square_sym{{p.x+widthh-32,p.y+23},"#"},
    minimize_sym{{p.x+widthh-47,p.y+23},"-"}
{
    top_bar.set_fill_color(Color::blue);
    top_bar2.set_fill_color(Color::blue);
    top_bar2.set_color(Color::invisible);
    exit_sym.set_font(Graph_lib::Font::courier_bold);
    exit_sym.set_font_size(20);
    square_sym.set_font(Graph_lib::Font::courier_bold);
    square_sym.set_font_size(20);
    minimize_sym.set_font(Graph_lib::Font::courier_bold);
    minimize_sym.set_font_size(20);
}


void Pseudo_window::set_width(int w)
{
    exit_sym.move(-Box::get_width()+w,0);
    square_sym.move(-Box::get_width()+w,0);
    minimize_sym.move(-Box::get_width()+w,0);
    text_top.move(-Box::get_width()+w,0);  //Bug causes move() to create a negative position. Couldn't afford to spend more time on it
    Box::set_width(w);
    top_bar.set_width(w);
    top_bar2.set_width(w);
}

void Pseudo_window::draw_lines() const
{
    for (int i = 0; i < vr.size(); i++) //draws attachments to pseudo_window
    {
        vr[i].draw();
    }
    
    Box::draw_lines();
    top_bar.draw_lines();
    top_bar2.draw_lines();
    exit_sym.draw_lines();
    square_sym.draw_lines();
    minimize_sym.draw_lines();
    text_top.draw_lines();
}
//EX 10---

//EX 11
Binary_tree::Binary_tree(int levelss) //levels==0 means no nodes, levels==1 means one node, levels==2 means one top node with two sub-nodes, level==3 follows same logic
    : levels{levelss}
{
    int r {50};
    int x_size {(16/19.2)*x_max()}; //assuming 16:9 display. scalling down a notch. weird division represents screen ratio
    int y_size {(9/10.8)*y_max()};
    //add() add center point to shape?
    if (levels==0);
    else
    {
        int number_of_nodes {1};
        vector<int>nodes_per_index(1);
        nodes_per_index.push_back(1);
        for (int i = 2; i <= levels; i++)
        {
            number_of_nodes*=2;
            nodes_per_index.push_back(number_of_nodes);
        }
        int y_division {y_size/levels};
        int x_division ;
        while(2*r*nodes_per_index[nodes_per_index.size()-1]>x_size) r/=2; //half node size if horizontal screen fill overflows
        for (int i = 1; i <= levels; i++)
        {
            for(int j = 1 ; j<=nodes_per_index[i]; j++)
            {
                x_division = x_size/(nodes_per_index[i]+1);
                Point center_node 
                {
                    x_division*j,
                    y_division*(i-1)+r
                };
                nodes.push_back(new Circle{center_node,r});
                nodes[nodes.size()-1].set_fill_color(Color::green);
            }
        }
        for (int i = 1; i < nodes.size(); i++)
        {
            connectors.push_back(new Arrow{
                s(nodes[(i-1)/2]),
                n(nodes[i])
            });
        }
    }
}

void Binary_tree::draw_lines() const
{
    for(int i = 0 ; i < nodes.size() ; i++)
        nodes[i].draw_lines();
    for(int i = 0 ; i < connectors.size() ; i++)
        connectors[i].draw_lines();
}
//EX 11---