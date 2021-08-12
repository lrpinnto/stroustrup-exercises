//CHAPTER 13 EX 06

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    const int win_x  {1600};
    const int win_y  {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    Box_text bb {{300,300},50,150,10,"Custom box with text"};
    Box_text autobox {{500,500},5,"Automated text box"};
    Mark m {{300,300},'X'};
    Mark h {{500,500},'X'};
    Mark z {n(autobox),'X'};
    Mark w {s(autobox),'X'};
    win.attach(bb);
    win.attach(m);
    win.set_label("a");
    win.wait_for_button();
    bb.set_font(Graph_lib::Font::courier_bold);
    bb.set_fill_color(Color::dark_green);
    win.set_label("Set fill Color, set font");
    win.wait_for_button();
    win.attach(autobox);
    win.attach(z);
    win.attach(w);
    win.attach(h);
    win.set_label("Auto text box");
    win.wait_for_button();
    autobox.set_font_size(30,true); 
    autobox.move(100,100);
    win.set_label("Font size and move");
    win.wait_for_button();
    autobox.set_font(Graph_lib::Font::courier_bold);
    autobox.set_label("long text TEST TEST TEST TEST TEST TEST TEST",true);
    autobox.set_color(Color::blue);
    win.set_label("Change font, change color, change text");
    win.wait_for_button();
    win.detach(autobox);
    win.detach(m);
    win.detach(bb);
    win.detach(h);
    win.detach(z);
    win.detach(w);
    win.set_label("clear");
    win.wait_for_button();

    Vector_ref<Box_text> top_row;
    top_row.push_back(new Box_text{{win_x*2/6,win_y*1/5},5,"Window"});
    top_row.push_back(new Box_text{{win_x*3/6,win_y*1/5},5,"Line_style"});
    top_row.push_back(new Box_text{{win_x*4/6,win_y*1/5},5,"Color"});
    Vector_ref<Box_text> middle_row;
    middle_row.push_back(new Box_text{{win_x*2/6,win_y*2/5},5,"Simple_window"});
    middle_row.push_back(new Box_text{{win_x*3/6,win_y*2/5},5,"Shape"});
    middle_row.push_back(new Box_text{{win_x*4/6,win_y*2/5},5,"Point"});
    Vector_ref<Box_text> bottom_row;
    bottom_row.push_back(new Box_text{{win_x*0/7,win_y*3/5},5,"Line"});
    bottom_row.push_back(new Box_text{{win_x*1/7,win_y*3/5},5,"Lines"});
    bottom_row.push_back(new Box_text{{win_x*2/7,win_y*3/5},5,"Polygon"});
    bottom_row.push_back(new Box_text{{win_x*3/7,win_y*3/5},5,"Axis"});
    bottom_row.push_back(new Box_text{{win_x*4/7,win_y*3/5},5,"Rectangle"});
    bottom_row.push_back(new Box_text{{win_x*5/7,win_y*3/5},5,"Text"});
    bottom_row.push_back(new Box_text{{win_x*6/7,win_y*3/5},5,"Image"});

    Vector_ref<Arrow> arrows;
    for (int i = 1; i <= top_row.size(); i++)
    {
        top_row[top_row.size()-i].set_fill_color(Color::green);
        top_row[top_row.size()-i].set_font_size(20,true);
        top_row[top_row.size()-i].set_font(Graph_lib::Font::times_bold);
        middle_row[middle_row.size()-i].set_fill_color(Color::green);
        middle_row[middle_row.size()-i].set_font_size(20,true);
        middle_row[middle_row.size()-i].set_font(Graph_lib::Font::times_bold);
        win.attach(top_row[top_row.size()-i]);
        win.attach(middle_row[top_row.size()-i]);
    }
    for (int i = 1; i <= bottom_row.size(); i++)
    {
        arrows.push_back(new Arrow{n(bottom_row[bottom_row.size()-i]),s(middle_row[1])});
        bottom_row[bottom_row.size()-i].set_fill_color(Color::green);
        bottom_row[bottom_row.size()-i].set_font_size(20,true);
        bottom_row[bottom_row.size()-i].set_font(Graph_lib::Font::times_bold);
        arrows[arrows.size()-1].set_fill_color(Color::black);
        win.attach(bottom_row[bottom_row.size()-i]);
        win.attach(arrows[arrows.size()-1]);
    }
    Arrow lonelyarrow {n(middle_row[0]),s(top_row[0])};
    lonelyarrow.set_fill_color(Color::black);
    win.attach(lonelyarrow);
    win.label("Chapter 12.7 Illustration");
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