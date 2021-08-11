//CHAPTER 13 EX 06

#include "./sources.h"
#include <stdexcept>

struct Box_text : Box
{
    Box_text(Point p, int lengthh, int widthh, int rr, const string& s); //user sets parameters manually
    Box_text(Point p, int rr, const string& s);  //adjusts box to input text

    void draw_lines() const;

    void set_label(const string& s) { t.set_label(s); }
	string label() const { return t.label(); }

	void set_font(Graph_lib::Font f) { t.set_font(f); }
	Graph_lib::Font font() const { return t.font(); }

	void set_font_size(int s) { t.set_font_size(s); }
	int font_size() const { return t.font_size(); }

    void move_text(int dx, int dy) {t.move(dx,dy);}
private:
    Text t;
};

Box_text::Box_text(Point p, int lengthh, int widthh, int rr, const string& s)
    : Box{p,lengthh,widthh,rr}, t{p,s} {t.move(0,(lengthh/2)+t.font_size()/2);} //only attempts to center the text vertically

Box_text::Box_text(Point p, int rr, const string& s)
    : Box{p,10,10,rr}, t{p,s} //placeholder values
{
    t.move(5,t.font_size());            //any magic constants are trial and error in an attempt to fit the Text snuggly within the boxes walls
    Box::set_height(t.font_size()+4);
    Box::set_width((t.font_size()/1.9)*s.size());
}

void Box_text::draw_lines() const
{
    Box::draw_lines();
    t.draw_lines();
}

int main()
try
{
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    Box_text bb {{300,300},50,150,10,"something something"};
    win.attach(bb);

    win.wait_for_button();
    bb.set_font(Graph_lib::Font::courier_bold);
    bb.set_fill_color(Color::dark_green);
    win.set_label("a");
    win.wait_for_button();
    Mark m {{500,500},'X'};
    Box_text sna {{500,500},5,"sjadj jksd jkshdfsgdfhgshfjfghjgshfjgfdghjsdhfgshjgfghfjghj"};
    
    win.attach(sna);
    win.wait_for_button();
    win.attach(m);
    win.wait_for_button();
    sna.set_font_size(30);  //box cant keep up with font changes yet
    sna.set_font(Graph_lib::Font::courier_bold);
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