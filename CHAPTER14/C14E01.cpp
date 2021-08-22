//CHAPTER 14 EX 01
//need to fix set_radius() and any other derived function from circle
#include "./sources.h"
#include <stdexcept>

class Smiley : public Circle
{
private:
    int r;
    Arc mouth;
    Ellipse eye1;
    Ellipse eye2;
public:
    Smiley(Point p, int rr);	// center and radius
    void draw_lines() const;
};

Smiley::Smiley(Point p, int rr)
    : Circle{p,rr}, r{rr}, mouth{{p.x, p.y + rr*4/10},(rr/3),-180}, eye1{{p.x+rr*cos(PI*4/6),p.y-rr*sin(PI*7/8)},rr/8,(rr*2)/8},
    eye2{{p.x+rr*cos(PI*2/6),p.y-rr*sin(PI*7/8)},rr/8,(rr*2)/8}
{
    Circle::set_fill_color(Color::yellow);
    eye1.set_fill_color(Color::black);
    eye2.set_fill_color(Color::black);
}

void Smiley::draw_lines() const
{
    Circle::draw_lines();
    mouth.draw_lines();
    eye1.draw_lines();
    eye2.draw_lines();
}

class Frowney : public Circle
{
private:
    int r;
    Arc mouth;
    Ellipse eye1;
    Ellipse eye2;
public:
    Frowney(Point p, int rr);	// center and radius
    void draw_lines() const;
};

Frowney::Frowney(Point p, int rr)
    : Circle{p,rr}, r{rr}, mouth{{p.x, p.y + rr*4/10+(rr/3)},(rr/3),180}, eye1{{p.x+rr*cos(PI*4/6),p.y-rr*sin(PI*7/8)},rr/8,(rr*2)/8},
    eye2{{p.x+rr*cos(PI*2/6),p.y-rr*sin(PI*7/8)},rr/8,(rr*2)/8}
{
    Circle::set_fill_color(Color::yellow);
    eye1.set_fill_color(Color::black);
    eye2.set_fill_color(Color::black);
}

void Frowney::draw_lines() const
{
    Circle::draw_lines();
    mouth.draw_lines();
    eye1.draw_lines();
    eye2.draw_lines();
}

class Smiley_hat : public Smiley
{
private:
    int r;
    Rectangle base;
    Rectangle top;
public:
    Smiley_hat(Point p, int rr);
    void draw_lines() const;
};

Smiley_hat::Smiley_hat(Point p, int rr)
    :Smiley{p,rr}, r{rr}, base{{p.x-rr/2,p.y-rr-rr/4},rr,(rr/3)}, top{{p.x-(rr*2)/4/2,p.y-rr-rr/4-(rr*3)/6},(rr*2)/4,(rr*3)/6}
{
    base.set_fill_color(Color::black);
    top.set_fill_color(Color::black);
}

void Smiley_hat::draw_lines() const
{
    Smiley::draw_lines();
    base.draw_lines();
    top.draw_lines();
}

class Frowney_hat : public Frowney
{
private:
    int r;
    Rectangle base;
    Rectangle top;
public:
    Frowney_hat(Point p, int rr);
    void draw_lines() const;
};

Frowney_hat::Frowney_hat(Point p, int rr)
    :Frowney{p,rr}, r{rr}, base{{p.x-rr/2,p.y-rr-rr/4},rr,(rr/3)}, top{{p.x-(rr*2)/4/2,p.y-rr-rr/4-(rr*3)/6},(rr*2)/4,(rr*3)/6}
{
    base.set_fill_color(Color::black); 
    top.set_fill_color(Color::black);
}

void Frowney_hat::draw_lines() const
{
    Frowney::draw_lines();
    base.draw_lines();
    top.draw_lines();
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"};
    Frowney gaee {{1000,500},200}; 
    Smiley gaaa {{500,500},200};
    win.attach(gaaa);
    win.attach(gaee);
    win.wait_for_button();
    win.detach(gaaa);
    win.detach(gaee);
    Frowney_hat gae {{1000,500},200}; 
    Smiley_hat gaa {{500,500},200};
    win.attach(gae);
    win.attach(gaa);
    win.wait_for_button();
    gaa.set_radius(100); //need to fix set_radius() and any other derived function from circle
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
