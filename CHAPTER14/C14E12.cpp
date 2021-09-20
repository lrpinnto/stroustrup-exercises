//CHAPTER 14 EX 12
//Unable to find a Structure that fits well with my code and already spent way too much time on this exercise
//Code below works. But Binary_tree_rectangle constructor doesn't call Binary_tree_rectangle::draw_nodes() like I hoped it would
//skipping for now
#include "./sources.h"
#include <stdexcept>

struct Binary_tree : Shape
{
    Binary_tree(int levelss);
    void draw_lines() const;
    void move(int dx, int dy);
    void set_fill_color(Color col);
    Color fill_color() const {return fillcolor;}
    void set_color(Color col);
	Color color() const { return llcolor; }

    virtual void draw_node(Point center_point, int);

	void set_style(Line_style sty); //doesn't work
	Line_style style() const { return lls; }
private:
    Color fillcolor {Color::invisible};
    Color llcolor {fl_color()};
    Line_style lls {0};
    int levels;
protected:
    Vector_ref<Shape>nodes;
    Vector_ref<Arrow>connectors;
    vector<Point>nodes_points;
    vector<int>distances;
};

void Binary_tree::draw_node(Point center_node, int r)
{
    nodes.push_back(new Circle{center_node,r});
    nodes[nodes.size()-1].set_fill_color(Color::green);
    if(nodes.size()>1)
    {
        //Needed to research and use dynamic_cast. See https://stackoverflow.com/questions/5313322/c-cast-to-derived-class
        connectors.push_back(new Arrow{
            s(dynamic_cast<Circle&>(nodes[(nodes.size()-2)/2])),
            n(dynamic_cast<Circle&>(nodes[nodes.size()-1]))
        });
    }
}

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
                nodes_points.push_back(center_node);
                distances.push_back(r);
                draw_node(center_node,r);
            }
        }
    }
}

void Binary_tree::move(int dx, int dy)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        nodes[i].move(dx,dy);
    }
    for (int i = 0; i < connectors.size(); i++)
    {
        connectors[i].move(dx,dy);
    }
}

void Binary_tree::set_fill_color(Color col) 
{ 
    fillcolor = col; 
    for (int i = 0; i < nodes.size(); i++)
    {
        nodes[i].set_fill_color(fillcolor);
    }
}

void Binary_tree::set_color(Color col) 
{ 
    llcolor = col;
    for (int i = 0; i < connectors.size(); i++)
    {
        connectors[i].set_color(llcolor);
    } 
}

void Binary_tree::set_style(Line_style sty) 
{ 
    lls = sty; 
    for (int i = 0; i < connectors.size(); i++)
    {
        connectors[i].set_style(lls);
    } 
}

void Binary_tree::draw_lines() const
{
    for(int i = 0 ; i < nodes.size() ; i++)
        nodes[i].draw();
    for(int i = 0 ; i < connectors.size() ; i++)
        connectors[i].draw_lines();
}

struct Binary_tree_rectangle : Binary_tree
{
    Binary_tree_rectangle(int levelss);
    void draw_node(Point center, int) override;
    void draw_lines() const;
private:
    Vector_ref<Shape>nodes;
    Vector_ref<Arrow>connectors;
};

Binary_tree_rectangle::Binary_tree_rectangle(int levelss)
    :Binary_tree{levelss}{
        for (int i = 0; i < nodes_points.size(); i++)
        {
            draw_node(nodes_points[i],distances[i]);
        }
    }

void Binary_tree_rectangle::draw_node(Point center_node, int distance)
{
    nodes.push_back(new Rectangle{center_node,distance,distance});
    nodes[nodes.size()-1].set_fill_color(Color::green);
    if(nodes.size()>1)
    {
        //Needed to research and use dynamic_cast. See https://stackoverflow.com/questions/5313322/c-cast-to-derived-class
        connectors.push_back(new Arrow{
            s(dynamic_cast<Rectangle&>(nodes[(nodes.size()-2)/2])),
            n(dynamic_cast<Rectangle&>(nodes[nodes.size()-1]))
        });
    }
}

void Binary_tree_rectangle::draw_lines() const
{
    for(int i = 0 ; i < nodes.size() ; i++)
        nodes[i].draw();
    for(int i = 0 ; i < connectors.size() ; i++)
        connectors[i].draw_lines();
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    Vector_ref<Binary_tree_rectangle> bt;
    for (int i = 0; i < 10; i++)
    {
        win.set_label("level "+to_string(i));
        bt.push_back(new Binary_tree_rectangle{i});
        win.attach(bt[bt.size()-1]);
        win.wait_for_button();
        win.detach(bt[bt.size()-1]);
    }

    win.attach(bt[3]);
    win.wait_for_button();
    bt[3].move(100,100);
    win.wait_for_button();
    bt[3].set_fill_color(Color::dark_yellow);
    win.wait_for_button();
    bt[3].set_style(Line_style(Line_style::dashdot, 30)); //doesn't work
    bt[3].set_color(Color::dark_red);
    win.wait_for_button();

}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
catch(...)
{
    // some more error reporting
    return 2;
}
