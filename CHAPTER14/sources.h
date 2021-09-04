//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' ../CHAPTER13/sources.cpp sources.cpp  C14E01.cpp `fltk-config --ldflags --use-images` -o C14E01

#include "../CHAPTER13/sources.h"

//EX 04
//Delete virtual function from a derived class
/*The best solution I have found so far to get a compile-time error when calling Ds method is by using a static_assert with a generic struct that inherits from false_type. 
As long as noone ever calls the method, the struct stays undefied and the static_assert won't fail.

If the method is called however, the struct is defined and its value is false, so the static_assert fails.

If the method is not called, but you try to call it on a pointer of the super class, then Ds method is not defined and you get an undefined reference compilation error.*/
//Reference: https://stackoverflow.com/questions/24609872/delete-virtual-function-from-a-derived-class

struct Immobile_Circle : Circle
{
    using Circle::Circle;
private:
    using Circle::move;  //The first would be to use using to change the visibility of the method to private, thus preventing others from using it. 
};                         //The problem with that solution is, that calling the method on a pointer of the super-class does not result in a compilation error.
//EX 04----

//EX 05
struct Striped_rectangle : Rectangle
{
    using Rectangle::Rectangle;
    void draw_lines() const;
};
//EX 05----

//EX 06
struct Striped_circle : Circle
{
    using Circle::Circle;
    void draw_lines() const;
};

int mod(int x);
//EX 06---

//EX 08
struct Octagon : Polygon
{
    Octagon(Point p, int rr, int anglee=0); //trick from C15. Sets 0 as the default value for anglee and makes it optional
    void draw_lines() const;
    Point center() const { return center_point; } 

	//void set_radius(int rr) { r=rr; }
	int radius() const { return r; }

    //void set_angle(int aa) {ref_angle=aa*PI/180.0;} //in degrees
    double angle() const { return ref_angle * 180 / PI; }
protected:
    void add(Point p);
private:
    int r;
    double ref_angle; //stored in rads
    Point center_point;
};
//EX 08---

//EX 09
struct Group : Shape{
    Group(){}
    Group(Vector_ref<Shape>&sp);
    void add(Shape& s) { vr.push_back(s); }

    void move(int dx, int dy) override;
    void move(int dx, int dy, int index);
    void set_color(Color col);
    void set_fill_color(Color col);
    void set_style(Line_style sty);
    void draw_lines() const override;
private:
    Vector_ref<Shape> vr;
};
//EX 09----

//EX 10
struct Resizeable_rectangle : Shape //work around because rectangle doesn't support size changes "on the fly"
{
    Resizeable_rectangle(Point xy, int ww, int hh) :w{ ww }, h{ hh }
	{
		if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
		add(xy);
	}
	Resizeable_rectangle(Point x, Point y) :w{ y.x - x.x }, h{ y.y - x.y }
	{
		if (h<=0 || w<=0) error("Bad rectangle: first point is not top left");
		add(x);
	}
    void set_height(int hh) {h=hh;}
    void set_width(int ww) {w=ww;}
    int height() const { return h; }
	int width() const { return w; }
    void draw_lines() const;
private:
    int h;
    int w;
};

struct Pseudo_window : Box
{
    Pseudo_window(Point p,int widthh,int heigthh,string labell);
    void set_label(string s ) {label_text = s; text_top.set_label(label_text);}
    string label() const {return label_text;}

    using Box::set_height;
    void set_width(int w);

    void draw_lines() const;

    void attach(Shape& pseudo_shape) {vr.push_back(pseudo_shape);} 
private:
    string label_text;
    Box top_bar;
    Resizeable_rectangle top_bar2;
    Text exit_sym;
    Text text_top;
    Text square_sym;
    Text minimize_sym;
    Vector_ref<Shape> vr;
};
//EX 10---

//EX 11
struct Binary_tree : Shape
{
    Binary_tree(int levelss);
    void draw_lines() const;
private:
    int levels;
    Vector_ref<Circle>nodes;
    Vector_ref<Arrow>connectors;
};
//EX 11---