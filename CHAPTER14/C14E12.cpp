//CHAPTER 14 EX 12

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
    Vector_ref<Shape>nodes;
    Vector_ref<Arrow>connectors;
};

void Binary_tree::draw_node(Point center_node, int r)
{
    nodes.push_back(new Circle{center_node,r});
    nodes[nodes.size()-1].set_fill_color(Color::green);
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
                draw_node(center_node,r});
            }
        }
        try  //coordinates need to be defined beforehand so we can connect the connectors. If not, use Shape's point.
        {
            for (int i = 1; i < nodes.size(); i++)
            {
                connectors.push_back(new Arrow{
                    s(nodes[(i-1)/2]),
                    n(nodes[i])
                });
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            for (int i = 1; i < nodes.size(); i++)
            {
                connectors.push_back(new Arrow{
                    nodes[(i-1)/2].point(0),
                    nodes[i].point(0)
                });
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
        nodes[i].draw_lines();
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
