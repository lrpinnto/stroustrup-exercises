//CHAPTER 13 EX 05
//Skipped for now. Need way to calculate ellipse arc
#include "./sources.h"
#include <stdexcept>

Point center(Ellipse& circ)
{
    return circ.center();
}
Point n(Ellipse& circ) //Major - x
{                       //Minor - y
    return {center(circ).x,center(circ).y - circ.minor()};
}
Point nw(Ellipse& circ)
{
    //return point thats 50% the length of the arc from PI/2 to PI
}

int main()
try
{
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    Ellipse el {Point{500,300},800,200};
    Circle c {Point{500,500},300};
    Vector_ref<Text> marking;
    marking.push_back(new Text{nw(c),"nw"});
    marking.push_back(new Text{n(c),"n"});
    marking.push_back(new Text{s(c),"s"});
    marking.push_back(new Text{e(c),"e"});
    marking.push_back(new Text{w(c),"w"});
    marking.push_back(new Text{center(c),"center"});
    marking.push_back(new Text{ne(c),"ne"});
    marking.push_back(new Text{se(c),"se"});
    marking.push_back(new Text{sw(c),"sw"});
    for (int i = 1; i<=marking.size(); i++)
    {
        win.attach(marking[marking.size()-i]);
        win.wait_for_button();
    }
    win.attach(c);
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