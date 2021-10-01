//CHAPTER 16 EX 02

#include "./sources.h" //need to create header files for this chapter

struct Checkerboard_window : My_window {
	Checkerboard_window(Point xy, int w, int h, const string& title ); //needs to be 4x4
private:
	Button button1;
    Button button2;
    Button button3;
    Button button4;
    Button button5;
    Button button6;
    Button button7;
    Button button8;
    Button button9;
    Button button10;
    Button button11;
    Button button12;
	
	static void cb_1(Address, Address);
    static void cb_2(Address, Address);
    static void cb_3(Address, Address);
    static void cb_4(Address, Address);
    static void cb_5(Address, Address);
    static void cb_6(Address, Address);
    static void cb_7(Address, Address);
    static void cb_8(Address, Address);
    static void cb_9(Address, Address);
    static void cb_10(Address, Address);
    static void cb_11(Address, Address);
    static void cb_12(Address, Address);
	void one(); 
    void two();
    void three(); 
    void four();
    void five(); 
    void six();
    void seven(); 
    void eight();
    void nine(); 
    void ten();
    void eleven(); 
    void twelve();
};

Checkerboard_window::Checkerboard_window(Point xy, int w, int h, const string& title) :
    Checkerboard_window(xy,w,h,title),
    button1(Point(x_max()/2-75,y_max()/2-75), 50, 50, "1", cb_1),
    button2(Point(x_max()/2-25,y_max()/2-25), 50, 50, "2", cb_2),
    button3(Point(x_max()/2+25,y_max()/2+25), 50, 50, "3", cb_3),
    button4(Point(x_max()/2+75,y_max()/2+75), 50, 50, "4", cb_4),
    button5(Point(x_max()/2-75,y_max()/2-75), 50, 50, "5", cb_5),
    button6(Point(x_max()/2-25,y_max()/2-25), 50, 50, "6", cb_6),
    button7(Point(x_max()/2+25,y_max()/2+25), 50, 50, "7", cb_7),
    button8(Point(x_max()/2+75,y_max()/2+75), 50, 50, "8", cb_8),
    button9(Point(x_max()/2-75,y_max()/2-75), 50, 50, "9", cb_9),
    button10(Point(x_max()/2-25,y_max()/2-25), 50, 50, "10", cb_10),
    button11(Point(x_max()/2+25,y_max()/2+25), 50, 50, "11", cb_11),
    button12(Point(x_max()/2+75,y_max()/2+75), 50, 50, "12", cb_12),
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

//------------------------------------------------------------------------------

void Checkerboard_window::one() //hide two
{
    button_pushed = true;
}

void Checkerboard_window::two() //hide one
{
    hide();
}

void Checkerboard_window::two() //reset hide
{
    hide();
}

//------------------------------------------------------------------------------

int main()
try
{
    Checkerboard_window win {Point{100,100},600,400,"EX 02"};
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
