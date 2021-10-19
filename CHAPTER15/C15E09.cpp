//CHAPTER 15 EX 9

#include "./sources.h"
#include <stdexcept>

//data set : http://wiki.stat.ucla.edu/socr/index.php/SOCR_Data_Dinov_020108_HeightsWeights

constexpr int xmax = 600; //window size
constexpr int ymax = 400;

constexpr int xoffset = 100; //distance from left-hand side of window to y axis
constexpr int yoffset = 60; //distance from bottom of window to x axis

constexpr int xspace = 40; //space beyond axis
constexpr int yspace = 40;

constexpr int xlength = xmax-xoffset-xspace;
constexpr int ylength = ymax-yoffset-yspace;

constexpr int base_height = 160;
constexpr int end_height = 195;

constexpr double xscale = double(xlength)/(end_height-base_height); //length of axes
constexpr double yscale = double(ylength)/100;

Scale xs {xoffset,base_height,xscale};
Scale ys {ymax-yoffset,0,-yscale};

struct Distribution
{
    int height, people;
};
struct Distribution_ucla
{
    int index;
    double height; //in inches
    int weight; //in pounds
};

int divs_by_five(double nr)
{
    return round(nr/5)*5;
}

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

istream& operator>>(istream& is, Distribution_ucla& d)
{
    char ch1 = 0;
    string s;
    string s2;
    double numbr {0};
    vector<double>vect;
    while(vect.size()!=3) //try to read a vector for values, line by line
    {
        if(is.eof()) 
        {
            is.clear(ios_base::failbit);
            return is;
        }
        getline(is,s);
        istringstream iss {s};
        while(iss >> ch1)
        {
            s2+=ch1;
            if(s2.find("<td>")!= string::npos )
            {
                s2.clear();
                iss>>ch1;
                if(isdigit(ch1) /*|| ch1=='.'*/)
                {
                    iss.unget();
                    iss>>numbr;
                    vect.push_back(numbr);
                }
                else iss.unget();
            }   
        }

        if (vect.size()!=3)
        {
            vect.clear();
            numbr=0;
            ch1=0;
            s.clear();
            s2.clear();
        }
    }
    if (vect.size()!=3) //if it gets to end of file without a vector
    {
        is.clear(ios_base::failbit);
        return is;
    }
    d.index=vect[0];
    d.height=vect[1];
    d.weight=vect[2];
    return is;
}

int main()
try
{
    Graph_lib::Window win {Point{100,100},xmax,ymax,"Group Height"};

    Axis x {Axis::x, Point{xoffset,ymax-yoffset},xlength,(end_height-base_height)/5,//difference between heights is 5
    "Height 160          165          170          175          180"
    "          185          190          195"};  
    x.label.move(-120,0);

    Axis y {Axis::y, Point{xoffset,ymax-yoffset},ylength,10,"% of population"};

    Line national_average{Point{xs(177),ys(0)},Point{xs(177),ys(100)}};
    national_average.set_style(Line_style::dash);

    string file_name {"input_data.txt"};
    ifstream ifs {file_name};
    if(!ifs) error("Can't open ",file_name);

    vector<pair<double,double>>vals;
    vector<int>vals_ucla;
    vector<pair<double,double>>vals_ucla_pairs;

    Open_polyline height_percentage_1;
    Open_polyline height_percentage_2;

    for (Distribution d; ifs>>d;)
    {
        if (d.height<base_height || end_height < d.height)
        {
            error("Height out of range");
        }

        vals.push_back(make_pair(d.height,d.people));
    }
    string file_ucla {"ucla_data_set.html"};
    ifstream ifs2 {file_ucla};
    if(!ifs2) error("Can't open ",file_ucla);
    for (Distribution_ucla d; ifs2>>d;) 
    {
        if (d.height*2.54<base_height || end_height < d.height*2.54)
        {
            error("Height out of range (ucla)");
        }

        vals_ucla.push_back(divs_by_five(d.height*2.54)); //change inches to cm and round to nearest divisible by 5 
    }
    
    sort(vals_ucla.begin(),vals_ucla.end());

    int counter {1};
    for (int i = 0; i < vals_ucla.size()-1; i++)
    {
        if(vals_ucla[i]==vals_ucla[i+1]) counter++;
        else{
            vals_ucla_pairs.push_back(make_pair(vals_ucla[i],counter));
            counter=1;
        }
    }
    if (vals_ucla[vals_ucla.size()-1]==vals_ucla[vals_ucla.size()-2])
    {
        vals_ucla_pairs.push_back(make_pair(vals_ucla[vals_ucla.size()-1],counter));
    }
    else vals_ucla_pairs.push_back(make_pair(vals_ucla[vals_ucla.size()-1],1));
    
    int total_people {0};
    for (pair<double,double> p: vals)
        total_people+=p.second;
    
    for (pair<double,double> p: vals)
        height_percentage_1.add(Point{xs(p.first),ys(p.second/total_people*100)});
    
    Text height_label {Point{20,height_percentage_1.point(0).y},"Group A"};
    height_percentage_1.set_color(Color::red);
    height_label.set_color(Color::red);

    for (pair<double,double> p: vals_ucla_pairs)
        height_percentage_2.add(Point{xs(p.first),ys(p.second/vals_ucla.size()*100)});
    
    Text height_label_2 {Point{20,height_percentage_2.point(0).y},"Group B"};
    height_percentage_2.set_color(Color::blue);
    height_label_2.set_color(Color::blue);


    win.attach(height_percentage_1);
    win.attach(height_percentage_2);
    win.attach(height_label);
    win.attach(height_label_2);
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
