//CHAPTER 15 EX 05

#include "./sources.h"
#include <stdexcept>

double term(double x)
{
    return 1.0/(2.0*(x)+1.0);
}

double leibniz(double x, int number_of_terms)
{
    double sum {0};
    int rounded_x {round(x)};
    int n {number_of_terms-1};
    for (int k = 0; k <=rounded_x; k++)
    {
        if(k>n) break;
        if (k%2==0)
        {
            sum+=term(k);
        }
        else sum-=term(k);
    }
    return sum;
}

int main()
try
{
    constexpr int xmax {1600};
    constexpr int ymax {600};

    constexpr int x_orig {xmax/2};
    constexpr int y_orig {ymax/2};
    const Point orig {x_orig, y_orig};

    constexpr int r_min {0};
    constexpr int r_max {50};

    constexpr int n_points {400};

    constexpr int x_scale {20};
    constexpr int y_scale {100};

    constexpr int xlength {1000};
    constexpr int ylength {400};

    Point tl {100,100};
    Simple_window win {tl,xmax,ymax,"Function graphs"}; 
    Axis x {Axis::Orientation::x,{orig.x-(xlength/2),orig.y},xlength,xlength/x_scale,"(0,0)"};
    Axis y {Axis::Orientation::y,{orig.x-(xlength/2),orig.y+(ylength/2)},ylength,ylength/y_scale,"1==100 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    x.label.set_color(Color::black);
    x.label.move(-50,0);
    y.label.set_color(Color::black);
    win.attach(x);
    win.attach(y);

    Function leibnizlimit {[](double x)->double{return PI/4.0;},r_min, r_max, {orig.x-(xlength/2),orig.y},n_points,x_scale,y_scale};
    leibnizlimit.set_color(Color::green);
    win.attach(leibnizlimit);
    Text llt {{orig.x-(xlength/2)-30,orig.y-75},"PI/4"};
    win.attach(llt);

    for (int n = 0; n < 50; ++n)
    {
        Function leibnizf {[n](double x){return leibniz(x,n);}, r_min, r_max, {orig.x-(xlength/2),orig.y},n_points,x_scale,y_scale };
        leibnizf.set_color(Color::blue);
        win.attach(leibnizf);
        win.set_label("terms:"+to_string(n));
        win.wait_for_button();
        win.detach(leibnizf);
    }
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