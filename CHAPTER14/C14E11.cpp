//CHAPTER 14 EX 11

#include "./sources.h"
#include <stdexcept>

struct Binary_tree : Shape
{
    Binary_tree(int levelss);
    void draw_lines() const;
private:
    int levels;
    Vector_ref<Circle>nodes;
    Vector_ref<Arrow>connectors;
};

Binary_tree::Binary_tree(int levelss) //levels==0 means no nodes, levels==1 means one node, levels==2 means one top node with two sub-nodes, level==3 follows same logic
    : levels{levelss}
{
    //add() add center point to shape?
    if (levels==0) break;
    int number_of_nodes {1};
    vector<int>nodes_per_index(1);
    nodes_per_index.push_back(1);
    for (int i = 2; i <= levels; i++)
    {
        number_of_nodes*=2;
        nodes_per_index.push_back(number_of_nodes);
    }
    int y_division {y_max()/levels};
    int x_division {x_max()/(nodes_per_index[nodes_per_index.size()-1])};
    for (int i = 1; i <= levels; i++)
    {
        for(int j = 1 ; j<=nodes_per_index[i]; j++)
        {
            Point center_node 
            {
                x_division/2*j,
                y_division/2*i
            };
            nodes.push_back(new Circle{center_node},50);
            nodes[nodes.size()-1].set_fill_color(Color::green);
        }
    }
}

void Binary_tree::draw_lines() const
{
    for(int i = 0 ; i < nodes.size() ; i++)
        nodes[i].draw_lines();
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

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
