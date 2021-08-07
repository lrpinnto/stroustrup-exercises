//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' sources.cpp  C13E01.cpp `fltk-config --ldflags --use-images` -o C13E01
//use above command to compile on this chapter
#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"

//EX 1

struct Arc : Ellipse { //apparently, only inherits from public. Also, declaring objects with the same name as circle seems to overload them
    Arc(Point p, int rr, double anglee); //angle in degrees because of fl_arc
    Arc(Point p, int ww, int hh, double anglee);
    
    void draw_lines() const;
    void set_angle(int anglee) { angle=anglee; }
private:
    int r;
    double angle;
    int w; //width
    int h; //height
};
//EX 1-------

