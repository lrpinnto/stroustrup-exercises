//CHAPTER 15 EX 8

#include "./sources.h"
#include <stdexcept>

constexpr int xmax = 600; //window size
constexpr int ymax = 400;

constexpr int xoffset = 100; //distance from left-hand side of window to y axis
constexpr int yoffset = 60; //distance from bottom of window to x axis

constexpr int xspace = 40; //space beyond axis
constexpr int yspace = 40;

constexpr int xlength = xmax-xoffset-xspace;
constexpr int ylength = ymax-yoffset-yspace;

constexpr int base_height = 170;
constexpr int end_height = 195;

constexpr double xscale = double(xlength)/(end_height-base_height); //length of axes
constexpr double yscale = double(ylength)/100;

class Scale
{
private:
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) :cbase{b}, vbase{vb}, scale{s} {}
    int operator()(int v) const {return cbase + (v-vbase)*scale; }
};

Scale xs {xoffset,base_height,xscale};
Scale ys {ymax-yoffset,0,-yscale};

struct Distribution
{
    int height, people;
};

istream& operator>>(istream& is, Distribution& d)
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if(is >> ch1 >> dd.height
            >>ch2>>dd.people
            >>ch3)
    {
        if (ch1!='(' || ch2!=':' || ch3!=')')
        {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else return is;
    d=dd;
    return is;
}

int main()
try
{
    Graph_lib::Window win {Point{100,100},xmax,ymax,"Group Height"};

    Axis x {Axis::x, Point{xoffset,ymax-yoffset},xlength,(end_height-base_height)/5,//difference between heights is 5
    "Height 170                 175                 180"
    "                 185                 190                 195"};  
    x.label.move(-120,0);

    Axis y {Axis::y, Point{xoffset,ymax-yoffset},ylength,10,"% of population"};

    Line national_average{Point{xs(182),ys(0)},Point{xs(182),ys(100)}};
    national_average.set_style(Line_style::dash);

    string file_name {"input_data.txt"};
    ifstream ifs {file_name};
    if(!ifs) error("Can't open ",file_name);

    vector<pair<double,double>>vals;

    Open_polyline height_percentage;

    for (Distribution d; ifs>>d;)
    {
        if (d.height<base_height || end_height < d.height)
        {
            error("Height out of range");
        }

        vals.push_back(make_pair(d.height,d.people));
    }
    int total_people {0};
    for (pair<double,double> p: vals)
        total_people+=p.second;
    
    for (pair<double,double> p: vals)
        height_percentage.add(Point{xs(p.first),ys(p.second/total_people*100)});
    
    Text height_label {Point{20,height_percentage.point(0).y},"Group A"};
    height_percentage.set_color(Color::red);
    height_label.set_color(Color::red);


    win.attach(height_percentage);
    win.attach(height_label);
    win.attach(x);
    win.attach(y);
    win.attach(national_average);
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