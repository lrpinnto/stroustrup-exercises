//CHAPTER 13 EX 18
//I believe the Polygon check is done intrinsically within Polygon::add(). No need to have another check inside the constructor?
#include "./sources.h"
#include <stdexcept>

//Unable to import both functions. Taken from Graph.cpp
inline pair<double,double> line_intersect(Point p1, Point p2, Point p3, Point p4, bool& parallel) 
{
    double x1 = p1.x;
    double x2 = p2.x;
	double x3 = p3.x;
	double x4 = p4.x;
	double y1 = p1.y;
	double y2 = p2.y;
	double y3 = p3.y;
	double y4 = p4.y;

	double denom = ((y4 - y3)*(x2-x1) - (x4-x3)*(y2-y1));
	if (denom == 0){
		parallel= true;
		return pair<double,double>(0,0);
	}
	parallel = false;
	return pair<double,double>( ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3))/denom,
								((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3))/denom);
}

bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4, Point& intersection){
   bool parallel;
   pair<double,double> u = line_intersect(p1,p2,p3,p4,parallel);
   if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1) return false;
   intersection.x = p1.x + u.first*(p2.x - p1.x);
   intersection.y = p1.y + u.first*(p2.y - p1.y);
   return true;
} 

struct Poly : Polygon
{
    Poly(initializer_list<Point> lst);
};

Poly::Poly(initializer_list<Point> lst)
{
    for (Point p : lst)
    {
        int np = number_of_points();
        if (1<np) 
        {	// check that thenew line isn't parallel to the previous one
            if (p==point(np-1)) error("polygon point equal to previous point");
            bool parallel;
            line_intersect(point(np-1),p,point(np-2),point(np-1),parallel);
            if (parallel)
                error("two polygon points lie in a straight line");
	    }

        for (int i = 1; i<np-1; ++i) 
        {	// check that new segment doesn't interset and old point
            Point ignore(0,0);
            if (line_segment_intersect(point(np-1),p,point(i-1),point(i),ignore))
                error("intersect in polygon");
        }
        Closed_polyline::add(p);
    }
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    list<Point>good_poly_list {{100,100},{100,200},{200,200},{200,100}};
    list<Point>bad_poly_list {{100,100},{100,200},{200,200},{200,100},{150,150}};
    Poly good_poly {{100,100},{100,200},{200,200}};
    Polygon pp;
    pp.add({100,100});
    pp.add({100,200});
    pp.add({200,200});
    win.attach(pp);
    pp.move(100,100);
    win.attach(good_poly);
    win.wait_for_button();
    Poly bad_poly {{100,100},{100,200},{200,200},{200,100},{150,250}};
    win.attach(bad_poly);
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
