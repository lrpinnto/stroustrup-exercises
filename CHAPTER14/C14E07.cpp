//CHAPTER 14 EX 07

#include "./sources.h"
#include <stdexcept>

struct Striped_closed_polyline : Closed_polyline
{
    using Closed_polyline::Closed_polyline;
    void draw_lines() const;
};

void Striped_closed_polyline::draw_lines() const
{
    //Create limiting square/rectangle
    int x_min {point(0).x};
    int x_max {0};
    int y_min {point(0).y};
    int y_max {0};
    for (int i = 0; i < number_of_points(); i++)
    {
        if(point(i).x<x_min) x_min=point(i).x;
        if(point(i).y<y_min) y_min=point(i).y;
        if(point(i).x>x_max) x_max=point(i).x;
        if(point(i).y>y_max) y_max=point(i).y;
    }
    if (fill_color().visibility()) {	// fill
        fl_color(fill_color().as_int());
        fl_line_style(0,0); //Line_style affects this type of fill. Override it. these are default line values. Which we want for filling
        //check for intersects, horizontally 5 pixels each time, from left to right. get the list of intersection points and draw lines accordingly
        //do this every 2 vertical lines
        Point intersection;
        vector<Point>intersections;
        for (int i = y_min; i < y_max; i+=2)
        {
            //check which pairs of points intersect then y axis on the given i (doing this out of efficency, maybe it's not the best way?)
            vector<pair<Point,Point>> pairs_of_points;              //A vector of pairs of points. In this context, that intersect the given i or y axis 
            if (point(number_of_points()-1).y < i < point(0).y || point(0).y < i < point(number_of_points()-1).y )   //do last pair, first
            {
                pairs_of_points.push_back({point(number_of_points()-1),point(0)});
            }
            for (int index = 0; index < number_of_points; index++)
            {
                if( point(index).y < i < point(index +1 ).y || point(index+1).y < i < point(index ).y ) //note:check if this needs to account for parity
                {
                    pairs_of_points.push_back({point(index),point(index+1)});
                }
            }

            for (int x_scan = x_min; x_scan < x_max; x_scan+=5)
            {
                for(pair<Point,Point> point_pair : pairs_of_points)
                {
                    if(line_segment_intersect(Point(x_scan,i),Point(x_scan+4,i),point_pair.first,point_pair.second,intersection))
                        intersections.push_back(intersection); //should always finish in pairs, ideally. Need to account for a the case of a vertex, that is, a point with the y coordinate matching i
                }
            }
            pairs_of_points.clear();

            //draw

            intersections.clear();
        }
        fl_color(color().as_int());	// reset color
        fl_line_style(Rectangle::style().style(),Rectangle::style().width()); //reset linestyle
    }
    if (color().visibility())
			Closed_polyline::draw_lines();
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

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
