//CHAPTER 14 EX 05

#include "./sources.h"
#include <stdexcept>

struct Striped_rectangle : Rectangle
{
    using Rectangle::Rectangle;
    void draw_lines() const;
};

void Striped_ectangle::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
        for (int i = 2; i < Rectangle::height(); i+=2)
        {
            fl_color(fill_color().as_int());
            fl_line(Rectangle::point(0).x, Rectangle::point(0).y + i, Rectangle::point(0).x + Rectangle::width(), Rectangle::point(0).y + i);
        }
        
		fl_rectf(point(0).x,point(0).y,w,h);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {	// edge on top of fill
		fl_color(color().as_int());
		fl_rect(point(0).x,point(0).y,w,h);
	}
}

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Striped_rectangle stre {{500,500},300,100};
    stre.set_fill_color(Color::blue);
    win.attach(stre);
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
