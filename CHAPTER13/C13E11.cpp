//CHAPTER 13 EX 11

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Ellipse eli {{500,500},300,200};
    Axis centerx {Axis::x,{500,500},400,40,"X"};
    Axis centery {Axis::y,{500,500},300,30,"Y"};
    Mark foci1 {{eli.focus1()},'1'};
    Mark foci2 {{eli.focus2()},'2'};
    // (x/a)² + (y/b)² = 1 <=> (y/b)² = 1 - (x/a)² <=>  y/b = sqrt( 1 - (x/a)² ) <=> y = sqrt( 1 - (x/a)² ) * b
    double a {eli.major()};
    double b {eli.minor()};
    double adjustment { b * sqrt( 1 - pow( (eli.focus1().x - eli.center().x)/a,2 ) ) };
    Point pointh {eli.focus1().x, eli.focus1().y + adjustment};
    Mark P {pointh, 'H'};
    Lines foci2point;
    foci2point.add(eli.focus2(),pointh);
    foci2point.add(eli.focus1(),pointh);
    win.attach(eli);
    win.attach(centerx);
    win.attach(centery);
    win.attach(foci1);
    win.attach(foci2);
    win.attach(P);
    win.attach(foci2point);
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