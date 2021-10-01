//CHAPTER 16 EX 04

#include "./sources.h" 

struct Shapes_window : My_window {
	Shapes_window(Point xy, int w, int h, const string& title ); 
private:
    vector<Shape&>shapes;
	In_box next_x;
    In_box next_y;
    In_box width_box;
    In_box height_box;
    Menu menu;
    Button menu_button;

    void hide_menu() {menu.hide(); menu_button.show();}

    void circle_pressed() {draw_shape(Color::red);hide_menu();}
    void square_pressed() {}
    void triangle_pressed() {}
    void hexagon_pressed() {}
    void clear_pressed() {shapes.clear();hide_menu();}
	
	static void cb_click(Address, Address);
    void draw_circle();

	void click();
};

Shapes_window::Shapes_window(Point xy, int w, int h, const string& title) :
    My_window(xy,w,h,title),
    button(Point(x_max()/2,y_max()/2), 50, 50, "Click", cb_click),
    img{Point(x_max()/2,y_max()/2),"someimage.jpg"}
{
    attach(button);
    attach(img);
}

void Shapes_window::cb_click(Address, Address pw)
{  
    reference_to<Shapes_window>(pw).click();    
}

//------------------------------------------------------------------------------

void Shapes_window::draw_circle() 
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    int width {width_box.get_int()};
    int height {height_box.get_int()};

    if(width!=height) //make ellipse instead
    {
        shapes.push_back(new Ellipse{Point{x,y},width,height});
    }
    else shapes.push_back(new Circle{Point{x,y},width});
}

//------------------------------------------------------------------------------

int main()
try
{
    Shapes_window win {Point{100,100},600,400,"EX 04"};
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
