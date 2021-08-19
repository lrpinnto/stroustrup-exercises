//CHAPTER 13 EX 14

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    Circle c {{1600/2,900/2},200};
    Circle c1 {{1600/2,900/2},100};
    Vector_ref<Right_triangle>ra;
    for (int i = 0; i < 360; i+=45)
    {
        ra.push_back(new Right_triangle{{1600/2,900/2},200,100,i});
        win.attach(ra[ra.size()-1]);
        win.wait_for_button();
    }
    win.attach(c);
    win.attach(c1);
    win.wait_for_button();

    for (int i = 0; i < ra.size(); i++)
    {
        win.detach(ra[i]);
    }
    win.detach(c);
    win.detach(c1);
    Vector_ref<Right_triangle>reft;
    int arcx;
    int arcy;
    for (int i = 0; i < 360; i+=360/8)
    {
        //tan(a) = OL/AL <=> tan (45/2) = OL/AL <=> OL = tan(45/2)*AL
        int arc_length {300*tan((PI/2)/4)};
        arcx = 300 * cos(i*(PI/180));
        arcy = 300 * sin(i*(PI/180));
        reft.push_back(new Right_triangle{{1600/2+arcx,900/2+arcy},300,arc_length,180-i});
        reft.push_back(new Right_triangle{{1600/2+arcx,900/2+arcy},arc_length,300,270-i});
        reft[reft.size()-1].set_fill_color(rand()%255);
        reft[reft.size()-2].set_fill_color(rand()%255);
        win.attach(reft[reft.size()-1]);
        win.attach(reft[reft.size()-2]);
    }
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