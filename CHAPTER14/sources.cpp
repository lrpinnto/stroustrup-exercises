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