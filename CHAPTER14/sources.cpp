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