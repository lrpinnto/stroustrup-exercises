// CHAPTER 25 TRY 02

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"

void poor(Shape* p, int sz)
{
    for(int i = 0; i<sz; ++i) p[i].draw();
}

void f(Shape* q, vector<Circle>& s0)
{
    Polygon s1[10];
    //Shape s2[10]; // "Graph_lib::Shape::Shape()" is inaccessible
    // initialize 
    Shape* p1 = new Rectangle{Point{0,0},Point{10,20}};
    poor(&s0[0],s0.size());
    poor(s1,10);
    //poor(s2,20); //undeclared
    poor(p1,1);
    delete p1;
    p1=0;
    poor(p1,1);
    //poor(q,max); //no instance of overloaded function "max" matches the required type
}

int main()
{
    Circle c {Point{0,0},10};
    vector<Circle> cv ;
    cv.push_back(c);
    f(&c,cv);
} // error: use of deleted function ‘Graph_lib::Circle::Circle(const Graph_lib::Circle&)’