//CHAPTER 15 EX 06

#include "./sources.h"
#include <stdexcept>

constexpr int ymax = 400;

class Scale //Add scale to header?
{
private:
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) :cbase{b}, vbase{vb}, scale{s} {}
    int operator()(int v) const {return cbase + (v-vbase)*scale; }
};

struct Bar_graph : Shape
{
    Bar_graph(Point p, const vector<double>& data, int xlength, int ylength) //Leave user to draw Axis independently
    void draw_lines() const;
private:
    Vector_ref<Rectangle> bars;
};

Bar_graph::Bar_graph(Point p, const vector<double>& data, int xlength, int ylength) 
{
    double ceil_value {data[0]};
    double floor_value {data[0]};
    for(double h : data)
    {
        if(h>ceil_value) ceil_value=h;
        if(h<floor_value) floor_value=h;
    }
    double xscale = double(xlength)/(data.size()); 
    double yscale = double(ylength)/ceil_value;
    Scale xs {p.x,0,xscale};
    Scale ys {ymax-p.y,floor_value,-yscale}; //to do: figure out how to get window size
                                            //usage of floor value here is most likely wrong. All bar graph start from 0

    int spacing {xs(0)-p.x}; //Because 0 will always be the first x since data is an indexed vector
    for (int i = 0; i < data.size(); i++)
    {
        bars.push_back(new Rectangle{Point{xs(i)-spacing,ys(data[i])},Point{xs(i)+spacing,p.y}});
    }
}

void Bar_graph::draw_lines() const
{
    for (int i = 0; i < bars.size(); i++)
    {
        bars[i].draw_lines();
    }
}

int main()
try
{
    int win_x {600};
    int win_y {600};
    Point tl {100,100};
    Graph_lib::Window win {tl,win_x,win_y,"Function graphs"}; 

    gui_main();
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
