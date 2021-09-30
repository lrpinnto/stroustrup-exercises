//CHAPTER 16 EX 01

#include "../sourcesgui/GUI.h"

//Based on the book example and not on Simple_window.h for better understanding

struct My_window : Window {
	My_window(Point xy, int w, int h, const string& title );
	void wait_for_button();
private:
	Button next_button;
    Button quit_button;
    bool button_pushed;
	
	static void cb_next(Address, Address); // callback for the next_button
    static void cb_quit(Address, Address); // callback for the quit_button
	void next(); 
    void quit();
};

My_window::My_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
    quit_button(Point(x_max()-70,20), 70, 20, "Quit", cb_quit),
    button_pushed(false)
{
    attach(next_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

bool My_window::wait_for_button()

{
    while(!button_pushed) Fl::wait()
    button_pushed = false;
    Fl::redraw();
}

//------------------------------------------------------------------------------

void My_window::cb_next(Address, Address pw)
{  
    reference_to<My_window>(pw).next();    
}

void My_window::cb_quit(Address, Address pw)
{  
    reference_to<My_window>(pw).quit();    
}

//------------------------------------------------------------------------------

void My_window::next()
{
    button_pushed = true;
}

void My_window::quit()
{
    hide();
}
//------------------------------------------------------------------------------

int main()
try
{
    My_window win {Point{100,100},600,400,"lines"};
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
