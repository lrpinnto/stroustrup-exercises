//CHAPTER 14 EX 01

#include "./sources.h"
#include <stdexcept>

class Smiley : public Circle
{
private:
    int r;
public:
    Smiley(Point p, int rr);	// center and radius
    void draw_lines const;
};

Smiley::Smiley(Point p, int rr)
    : Circle{p,rr}, r{rr} 
{
    Circle::set_fill_color(Color::yellow);
    Arc mouth {{p.x + r, p.y + r/2},(1/3)r,-180};
    Ellipse eye1 {{p.x+r*cos((3/4)*PI),p.y+r*sin((3/4)*PI)},r/4,(r/4)*2};
    eye1.set_fill_color(Color::black);
    Ellipse eye2 {{p.x+r*cos((1/4)*PI),p.y+r*sin((1/4)*PI)},r/4,(r/4)*2};
    eye2.set_fill_color(Color::black);
}

Smiley::draw_lines() const
{
    Circle::draw_lines();
    Arc::draw_lines();
    Ellipse::draw_lines();
}

class Frowney : public Circle
{
private:
    int r;
public:
    Frowney(Point p, int rr);	// center and radius
    void draw_lines const;
};

Frowney::Frowney(Point p, int rr)
    : Circle{p,rr}, r{rr} 
{
    Circle::set_fill_color(Color::yellow);
    Arc mouth {{p.x + r, p.y + r/2},(1/3)r,-180};
    Ellipse eye1 {{p.x+r*cos((3/4)*PI),p.y+r*sin((3/4)*PI)},r/4,(r/4)*2};
    eye1.set_fill_color(Color::black);
    Ellipse eye2 {{p.x+r*cos((1/4)*PI),p.y+r*sin((1/4)*PI)},r/4,(r/4)*2};
    eye2.set_fill_color(Color::black);
}

Frowney::draw_lines() const
{
    Circle::draw_lines();
    Arc::draw_lines();
    Ellipse::draw_lines();
}

class Smiley_hat : public Smiley
{
private:
    int r;
public:
    Smiley_hat(Point p, int rr);
    void draw_lines const;
};

Smiley_hat::Smiley_hat(Point p, int rr)
    :Smiley{p,rr}, r{rr}
{
    Rectangle base {{p.x,p.y-(1/3)*r},r,(1/3)*r};
    base.set_fill_color(Color::black);
    Rectangle top {{p.x+(2/4)*r,p.y-r},r*(2/4),(2/3)*r};
    top.set_fill_color(Color::black);
}

void Smiley_hat::draw_lines() const
{
    Smiley::draw_lines();
    Rectangle::draw_lines();
}

class Frowney_hat : public Frowney
{
private:
    int r;
public:
    Frowney_hat(Point p, int rr);
    void draw_lines const;
};

Frowney_hat::Frowney_hat(Point p, int rr)
    :Frowney{p,rr}, r{rr}
{
    Rectangle base {{p.x,p.y-(1/3)*r},r,(1/3)*r};
    base.set_fill_color(Color::black);
    Rectangle top {{p.x+(2/4)*r,p.y-r},r*(2/4),(2/3)*r};
    top.set_fill_color(Color::black);
}

void Frowney_hat::draw_lines() const
{
    Frowney::draw_lines();
    Rectangle::draw_lines();
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

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
