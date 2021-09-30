//CHAPTER 16 DRILL

//Compile with: g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp C16DRILL.cpp `fltk-config --ldflags --use-images` -o C16DRILL

#include "../sourcesgui/GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window
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
    Menu style_menu;
    Button menu_style_button;

    void change(Color c) { lines.set_color(c); }
    void change_style(Line_style ls) { lines.set_style(ls); }

    void hide_menu() {color_menu.hide(); menu_button.show();}
    void hide_menu_style() {style_menu.hide();menu_style_button.show();}

    void red_pressed() {change(Color::red);hide_menu();}
    void blue_pressed() {change(Color::blue);hide_menu();}
    void black_pressed() {change(Color::black); hide_menu();}
    void solid_pressed() {change_style(Line_style::solid); hide_menu_style();}
    void dash_pressed() {change_style(Line_style::dash); hide_menu_style();}
    void dot_pressed() {change_style(Line_style::dot); hide_menu_style();}
    void dashdot_pressed() {change_style(Line_style::dashdot); hide_menu_style();}
    void dashdotdot_pressed() {change_style(Line_style::dashdotdot); hide_menu_style();}
    void menu_pressed() {menu_button.hide(); color_menu.show();}
    void menu_style_pressed() {menu_style_button.hide(); style_menu.show();}
    void next();
    void quit();
    //callback functions
    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
    static void cb_solid(Address, Address);
    static void cb_dash(Address, Address);
    static void cb_dot(Address, Address);
    static void cb_dashdot(Address, Address);
    static void cb_dashdotdot(Address, Address);
    static void cb_menu_style(Address, Address);
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-150,0},70,20,"Next point",cb_next},
    quit_button{Point{x_max()-70,0},70,20,"Quit",cb_quit},
    next_x{Point{x_max()-310,0},50,20,"next x:"},
    next_y{Point{x_max()-210,0},50,20,"next y:"},
    xy_out{Point{100,0},100,20,"current xy:"},
    //Step 3
    color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
    menu_button{Point{x_max()-80,30},80,20,"color menu", cb_menu},
    //Step 4
    style_menu{Point{50,y_max()-20},70,20,Menu::horizontal,"style"},
    menu_style_button{Point{50,y_max()-20},80,20,"style menu",cb_menu_style}
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

    style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    style_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
    style_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
    style_menu.attach(new Button{Point{0,0},0,0,"dashdot",cb_dashdot});
    style_menu.attach(new Button{Point{0,0},0,0,"dashdotdot",cb_dashdotdot});
    attach(style_menu);

    style_menu.hide();
    attach(menu_style_button);

    attach(lines);
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    //update current position readout
    ostringstream ss;
    ss<<'('<<x<<','<<y<<')';
    xy_out.put(ss.str());

    redraw();
}

void Lines_window::quit()
{
    hide(); //FLTK function
}

//callbacks

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_blue(Address, Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}
void Lines_window::cb_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
}
void Lines_window::cb_next(Address, Address pw)
{
    reference_to<Lines_window>(pw).next();
}
void Lines_window::cb_quit(Address, Address pw)
{
    reference_to<Lines_window>(pw).quit();
}
void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}
void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}
void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}
void Lines_window::cb_dashdot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dashdot_pressed();
}
void Lines_window::cb_dashdotdot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dashdotdot_pressed();
}
void Lines_window::cb_menu_style(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_style_pressed();
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