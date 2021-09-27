//CHAPTER 14 EX 16

#include "./sources.h"
#include <stdexcept>

int main()
{
    Controller_test ct;
    ct.set_level(20);
    cout<<"\nswitch status:";
    ct.show();
    ct.on();
    cout<<"\nswitch status:";
    ct.show();
    cout<<"\nlevel:";
    ct.get_level();
    cout<<"\n\n";

    //------

    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Circle c {{100,100},100};

    Control_shape cs {c};

    //Control_shape cs_test; no default constructor exists for class "Control_shape". -> as expected

    win.attach(c);
    win.set_label("Normal Circle");
    win.wait_for_button();
    cs.set_level(3);
    cs.set_level_style(3);
    cout<<"\nswitch status:";
    cs.show();
    win.set_label("Colorstyle");
    win.wait_for_button();
    cs.off();
    win.set_label("off()");
    win.wait_for_button();
    cs.on();
    win.set_label("on()");
    win.wait_for_button();
    //Check if Control_shape constructor defines status correctly
    Rectangle r {{100,100},100,100};
    r.set_color(Color::invisible);
    Control_shape cs2 {r};
    cout<<"\nShould be 0: ";
    cs2.show();
}