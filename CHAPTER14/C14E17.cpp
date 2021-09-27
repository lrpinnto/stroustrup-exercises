//CHAPTER 14 EX 17

#include "./sources.h"
#include <stdexcept>

//REFERENCE: https://www.cs.uah.edu/~rcoleman/CS307/SelectedTopics/Exceptions.html

int main()
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Text title {{700,20},"Exceptions"};
    title.set_font_size(20);
    title.set_font(Graph_lib::Font::courier_bold);
    Text sub_title {{700,50},"C++ Exception Classes"};
    sub_title.set_font_size(20);
    sub_title.set_font(Graph_lib::Font::courier_bold);
    Text topic {{100,100},"#include <stdexcept>"};
    topic.set_font_size(20);
    topic.set_font(Graph_lib::Font::courier_bold);
    win.attach(title);
    win.attach(sub_title);
    win.attach(topic);

    Vector_ref<Box_text>vr;
    Vector_ref<Arrow>vr2;
    //--
    vr.push_back(new Box_text{{900,300},5,"exception"}); 
    vr[0].set_fill_color(Color::magenta);
    vr[0].set_font(Graph_lib::Font::helvetica_bold_italic);
    //--
    vr.push_back(new Box_text{{100,400},5,"bad_alloc"});
    vr[1].set_fill_color(Color::blue);
    vr[1].set_font(Graph_lib::Font::helvetica_bold_italic);
    vr.push_back(new Box_text{{500,400},5,"logic_error"});
    vr[2].set_fill_color(Color::green);
    vr[2].set_font(Graph_lib::Font::helvetica_bold_italic);
    vr.push_back(new Box_text{{900,400},5,"runtime_error"});
    vr[3].set_fill_color(Color::blue);
    vr[3].set_font(Graph_lib::Font::helvetica_bold_italic);
    vr.push_back(new Box_text{{1300,400},5,"bad_cast"});
    vr[4].set_fill_color(Color::red);
    vr[4].set_font(Graph_lib::Font::helvetica_bold_italic);

    vr2.push_back(new Arrow{n(vr[1]),s(vr[0])});
    vr2.push_back(new Arrow{n(vr[2]),s(vr[0])});
    vr2.push_back(new Arrow{n(vr[3]),s(vr[0])});
    vr2.push_back(new Arrow{n(vr[4]),s(vr[0])});
    //--
    vr.push_back(new Box_text{{100,500},5,"length_error"});
    vr[5].set_fill_color(Color::green);
    vr[5].set_font(Graph_lib::Font::helvetica_bold_italic);
    vr.push_back(new Box_text{{100,600},5,"domain_error"});
    vr[6].set_fill_color(Color::green);
    vr[6].set_font(Graph_lib::Font::helvetica_bold_italic);
    vr.push_back(new Box_text{{100,700},5,"out_of_range"});
    vr[7].set_fill_color(Color::green);
    vr[7].set_font(Graph_lib::Font::helvetica_bold_italic);
    vr.push_back(new Box_text{{100,800},5,"invalid_argument"});
    vr[8].set_fill_color(Color::green);
    vr[8].set_font(Graph_lib::Font::helvetica_bold_italic);
    vr.push_back(new Box_text{{1100,500},5,"range_error"});
    vr[9].set_fill_color(Color::blue);
    vr[9].set_font(Graph_lib::Font::helvetica_bold_italic);
    vr.push_back(new Box_text{{1100,600},5,"overflow_error"});
    vr[10].set_fill_color(Color::blue);
    vr[10].set_font(Graph_lib::Font::helvetica_bold_italic);
    vr.push_back(new Box_text{{1100,700},5,"underflow_error"});
    vr[11].set_fill_color(Color::blue);
    vr[11].set_font(Graph_lib::Font::helvetica_bold_italic);

    vr2.push_back(new Arrow{n(vr[5]),s(vr[2])});
    vr2.push_back(new Arrow{n(vr[6]),s(vr[2])});
    vr2.push_back(new Arrow{n(vr[7]),s(vr[2])});
    vr2.push_back(new Arrow{n(vr[8]),s(vr[2])});

    vr2.push_back(new Arrow{n(vr[9]),s(vr[3])});
    vr2.push_back(new Arrow{n(vr[10]),s(vr[3])});
    vr2.push_back(new Arrow{n(vr[11]),s(vr[3])});

    for (int i = 0; i < vr.size(); i++)
        win.attach(vr[i]);

    for (int i = 0; i < vr2.size(); i++)
        win.attach(vr2[i]);
    
    win.wait_for_button();
}
