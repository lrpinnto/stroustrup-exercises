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

//EX 02
Checkerboard_window::Checkerboard_window(Point xy, int w, int h, const string& title)
    :   My_window{xy,w,h,title},
        button1{Point{x_max()/2-75,y_max()/2-75}, 50, 50, "1", cb_1},
        button2{Point{x_max()/2-25,y_max()/2-75}, 50, 50, "2", cb_2},
        button3{Point{x_max()/2+25,y_max()/2-75}, 50, 50, "3", cb_3},
        button4{Point{x_max()/2+75,y_max()/2-75}, 50, 50, "4", cb_4},
        button5{Point{x_max()/2-75,y_max()/2-25}, 50, 50, "5", cb_5},
        button6{Point{x_max()/2-25,y_max()/2-25}, 50, 50, "6", cb_6},
        button7{Point{x_max()/2+25,y_max()/2-25}, 50, 50, "7", cb_7},
        button8{Point{x_max()/2+75,y_max()/2-25}, 50, 50, "8", cb_8},
        button9{Point{x_max()/2-75,y_max()/2+25}, 50, 50, "9", cb_9},
        button10{Point{x_max()/2-25,y_max()/2+25}, 50, 50, "10", cb_10},
        button11{Point{x_max()/2+25,y_max()/2+25}, 50, 50, "11", cb_11},
        button12{Point{x_max()/2+75,y_max()/2+25}, 50, 50, "12", cb_12},
        button13{Point{x_max()/2-75,y_max()/2+75}, 50, 50, "13", cb_13},
        button14{Point{x_max()/2-25,y_max()/2+75}, 50, 50, "14", cb_14},
        button15{Point{x_max()/2+25,y_max()/2+75}, 50, 50, "15", cb_15},
        button16{Point{x_max()/2+75,y_max()/2+75}, 50, 50, "16", cb_16},
        random_box{Point{0,0},100,20,"random output: "}
{
    attach(button1);
    attach(button2);
    attach(button3);
    attach(button4);
    attach(button5);
    attach(button6);
    attach(button7);
    attach(button8);
    attach(button9);
    attach(button10);
    attach(button11);
    attach(button12);
    attach(button13);
    attach(button14);
    attach(button15);
    attach(button16);
    attach(random_box);
}

void Checkerboard_window::cb_1(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).one();    
}
void Checkerboard_window::cb_2(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).two();    
}
void Checkerboard_window::cb_3(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).three();    
}
void Checkerboard_window::cb_4(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).four();    
}
void Checkerboard_window::cb_5(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).five();    
}
void Checkerboard_window::cb_6(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).six();    
}
void Checkerboard_window::cb_7(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).seven();    
}
void Checkerboard_window::cb_8(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).eight();    
}
void Checkerboard_window::cb_9(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).nine();    
}
void Checkerboard_window::cb_10(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).ten();    
}
void Checkerboard_window::cb_11(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).eleven();    
}
void Checkerboard_window::cb_12(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).twelve();    
}
void Checkerboard_window::cb_13(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).thirteen();    
}
void Checkerboard_window::cb_14(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).fourteen();    
}
void Checkerboard_window::cb_15(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).fifteen();    
}
void Checkerboard_window::cb_16(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).sixteen();    
}

//------------------------------------------------------------------------------

void Checkerboard_window::one() //hide two
{
    button2.hide();
}

void Checkerboard_window::two() //hide one
{
    button1.hide();
}

void Checkerboard_window::three() //reset hide and color
{
    button1.show();
    button2.show();
}
void Checkerboard_window::four() //turn row into random colors
{
    //Author suggests color change but not sure how to achieve this
}

void Checkerboard_window::five() 
{
    button5.move(rand()%x_max(),rand()%y_max());
}

void Checkerboard_window::six() //reset hide
{
    random_box.put(button6.loc.x);
}
void Checkerboard_window::seven() //weird pointer thing
{
    int abc ;
    int* ptr = &abc;
    random_box.put(to_string(ptr));
}

void Checkerboard_window::eight() 
{
    random_box.move(rand()%x_max(),rand()%y_max());
}
void Checkerboard_window::nine() //reset hide
{
    //do things
}
void Checkerboard_window::ten() //hide two
{
    //do things
}
void Checkerboard_window::eleven() //hide one
{
    //do things
}
void Checkerboard_window::twelve() //reset hide
{
    //do things
}
void Checkerboard_window::thirteen() //reset hide
{
    //do things
}
void Checkerboard_window::fourteen() //hide two
{
    //do things
}

void Checkerboard_window::fifteen() //hide one
{
    //do things
}

void Checkerboard_window::sixteen() //reset hide
{
    //do things
}
//------------------------------------------------------------------------------
//EX 02--