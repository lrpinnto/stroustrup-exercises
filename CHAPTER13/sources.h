//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' sources.cpp  C13E01.cpp `fltk-config --ldflags --use-images` -o C13E01
//use above command to compile on this chapter
#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"

constexpr double PI = 3.14159265;

//EX 1

struct Arc : Ellipse { //apparently, only inherits from public. Also, declaring objects with the same name as circle seems to overload them
    Arc(Point p, int rr, double anglee, double angle_startt); //angle in degrees because of fl_arc
    Arc(Point p, int ww, int hh, double anglee, double angle_startt);
    Arc(Point p, int ww, int hh, double anglee);
    Arc(Point p, int rr, double anglee);
    
    void draw_lines() const;
    void set_angle(int anglee) { angle=anglee; }
private:
    double angle_start;
    int r;
    double angle;
    int w; //width
    int h; //height
};
//EX 1-------

//EX 2
struct Box : Shape {
    Box(Point p, int lengthh, int widthh, int rr);

    void draw_lines() const;
private:
    int length; //y
    int width; //x //both widths and lengths need to match to make a box
    int r;
};
//EX 2------

//EX 3
struct Arrow : Line
{
    Arrow(Point p1, Point p2);  //standard arrow, no frills
    Arrow(Point p1, Point p2, int lengthh, double anglee); //custom arrow

    void set_arrow_angle(double new_angle) {adjustment_angle=new_angle;}
    void set_arrow_length(int new_length) {length=new_length;}

    void draw_lines() const;
private:
    double angle;
    int length;
    double adjustment_angle;
};
//EX 3---------