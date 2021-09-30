//CHAPTER 16 DRILL

#include "../sourcesgui/GUI.h"

struct Lines_window : Window
{
    Lines_window(Point xy, int w, int h, const string& title);
    //Open_polyline lines;

    //Step 3
    //Menu color_menu;

    /*static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    
    void red_pressed() {change(Color::red);}
    void blue_pressed() {change(Color::blue);}
    void black_pressed() {change(Color::black);}

    void change(Color c) { lines.set_color(c); }*/
private:
    Open_polyline lines;
    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button menu_button;

    void change(Color c) { lines.set_color(c); }

    void hide_menu() {color_menu.hide(); menu_button.show();}

    void red_pressed() {change(Color::red);hide_menu();}
    void blue_pressed() {change(Color::blue);hide_menu();}
    void black_pressed() {change(Color::black); hide_menu();}
    void menu_pressed() {menu_button.hide(); color_menu.show();}
    void next();
    void quit();
    //callback functions
    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{xy,w,h,"Next point",cb_next},
    quit_button{xy,w,h,"Quit",cb_quit},
    next_x{xy,50,20,"next x:"},
    next_y{xy,50,20,"next y:"},
    xy_out{xy,50,20,"current xy:"},
    //Step 3
    color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
    menu_button{Point{x_max()-80,30},80,20,"color menu", cb_menu}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);

    //Step 3
    xy_out.put("no point");
    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    attach(color_menu);

    color_menu.hide();
    attach(menu_button);
    attach(lines);
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    //update current position readout
    ostringstream ss;
    ss<<'('<<x<<','<<')';
    xy_out.put(ss.str());

    redraw();
}

void Lines_window::quit()
{
    hide(); //FLTK function
}

int main()
try
{
    Lines_window win {Point{100,100},600,400,"lines"};
    return gui_main();
}
catch(exception& e)
{
    std::cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr<<"Some exception\n";
    return 2;
}
