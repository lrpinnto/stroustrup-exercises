//CHAPTER 16 EX 03

#include "./sources.h" //need to create header files for this chapter

struct Image_window : My_window {
	Image_window(Point xy, int w, int h, const string& title ); 
private:
	Button button;
    Image img;
	
	static void cb_click(Address, Address);
	void click();
};

Image_window::Image_window(Point xy, int w, int h, const string& title) :
    My_window(xy,w,h,title),
    button(Point(x_max()/2,y_max()/2), 50, 50, "Click", cb_click),
    img{Point(x_max()/2,y_max()/2),"someimage.jpg"}
{
    attach(button);
    attach(img);
}

void Image_window::cb_click(Address, Address pw)
{  
    reference_to<Image_window>(pw).click();    
}

//------------------------------------------------------------------------------

void Image_window::click() //hide two
{
    pair<double> coords (rand()%x_max(),rand%y_max());
    button.move(coords.first,coords.second);
    img.move(coords.first,coords.second);
}


//------------------------------------------------------------------------------

int main()
try
{
    Image_window win {Point{100,100},600,400,"EX 03"};
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
