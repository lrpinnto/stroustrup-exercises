//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' ../CHAPTER13/sources.cpp ../CHAPTER14/sources.cpp ../CHAPTER15/sources.cpp sources.cpp  C16EXX.cpp `fltk-config --ldflags --use-images` -o C16EXX

#include "./sources.h"

//EX 01
My_window::My_window(Point xy, int w, int h, const string& title) :
    Window{xy,w,h,title},
    next_button{Point{x_max()-70,0}, 70, 20, "Next", cb_next},
    quit_button{Point{x_max()-70,20}, 70, 20, "Quit", cb_quit},
    next_pushed{false},
    quit_pushed{false}
{
    attach(next_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

void My_window::wait_for_button()

{
    while(!next_pushed && !quit_pushed) Fl::wait();
    if(next_pushed)
    {
        next_pushed = false;
        Fl::redraw();
    }
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
    next_pushed = true;
}

void My_window::quit()
{
    quit_pushed = true;
    hide();
}
//------------------------------------------------------------------------------
//EX 01--