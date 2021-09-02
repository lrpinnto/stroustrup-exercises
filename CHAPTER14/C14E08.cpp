//CHAPTER 14 EX 08

#include "./sources.h"
#include <stdexcept>

struct Octagon : Polygon
{
    Octagon(Point p, int rr);
    void draw_lines() const;
    Point center() const { return point(0); } //needs proper center() adjusted with angle

	void set_radius(int rr) { r=rr; }
	int radius() const { return r; }

    void set_angle(int aa) {angle=aa*PI/180.0;} //in degrees
    double angle() const { return angle * 180 / PI; }
protected:
    void add(Point p);
private:
    int r;
    double angle; //stored in rads
};

Octagon::Octagon(Point p, int rr)
    : r{rr}, angle{0}
{
    if(r<2) error("small radius on Octagon()"); //find minimum radius that forms a Octagon
    const int N {8};
    double smallest_rad_division = 2*PI/N+angle; //dividing full circle into N amount of points
    for (int i = 0; i < N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i;
        Polygon::add(Point{sin(radangle)*r+p.x,cos(radangle)*r+p.y});
    }
}

void Octagon::draw_lines() const
{
    Polygon::draw_lines();
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    //TESTING
    Octagon oct {{500,500},100};
    cout<<oct.color()<<" "<<oct.fill_color()<<" "<<oct.number_of_points()<<" "<<oct.style()<<"" <<oct.point(0)<<" "<<oct.center()<<" "<<oct.radius();
    win.attach(oct);
    win.wait_for_button();
    oct.set_fill_color(Color::dark_green);
    oct.move(200,200);
    oct.set_color(Color::red);
    oct.set_style(Line_style(Line_style::dashdotdot,6));
    oct.set_radius()
    win.wait_for_button();
    oct.add(); //set as protected on purpose. Should fail.
    win.wait_for_button()
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
