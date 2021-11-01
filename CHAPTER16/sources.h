//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' ../CHAPTER13/sources.cpp ../CHAPTER14/sources.cpp ../CHAPTER15/sources.cpp sources.cpp  C16EXX.cpp `fltk-config --ldflags --use-images` -o C16EXX

#include "../CHAPTER15/sources.h"

//EX 01
struct My_window : Graph_lib::Window {
	My_window(Point xy, int w, int h, const string& title );
	void wait_for_button();
private:
	Button next_button;
    Button quit_button;
    bool next_pushed;
    bool quit_pushed;
	
	static void cb_next(Address, Address); // callback for the next_button
    static void cb_quit(Address, Address); // callback for the quit_button
	void next(); 
    void quit();
};
//EX 01--

//EX 02
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
    Button button13;
    Button button14;
    Button button15;
    Button button16;
    Out_box random_box;
	
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
    static void cb_13(Address, Address);
    static void cb_14(Address, Address);
    static void cb_15(Address, Address);
    static void cb_16(Address, Address);
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
    void thirteen(); 
    void fourteen();
    void fifteen(); 
    void sixteen();
};
//EX 02--

//EX 03
struct Image_window : My_window {
	Image_window(Point xy, int w, int h, const string& title ); 
private:
	Button button;
    Image img;
	
	static void cb_click(Address, Address);
	void click();
};
//EX 03--

//EX 04
struct Shapes_window : My_window {
	Shapes_window(Point xy, int w, int h, const string& title ); 
private:
    vector<Shape*>shapes; //Pointer stuff introduced in chapter 17. Only used because I really wanted to have a clear_shapes()
	In_box next_x;        // Should've probably used Vector_ref instead but this didn't allow me to clear the vector
    In_box next_y;
    In_box width_box;
    In_box height_box;
    Menu menu;
    Button menu_button;
    Button clear_button;

    void hide_menu() {menu.hide(); menu_button.show();}

    void circle_pressed() {draw_circle();hide_menu();}
    void square_pressed() {draw_square();hide_menu();}
    void triangle_pressed() {draw_triangle();hide_menu();}
    void hexagon_pressed() {draw_hexagon();hide_menu();}
    void clear_pressed() {clear_shapes();}
    void menu_pressed() {menu_button.hide(); menu.show();}
	
	static void cb_circle(Address, Address);
    static void cb_square(Address, Address);
    static void cb_triangle(Address, Address);
    static void cb_hexagon(Address, Address);
    static void cb_clear(Address, Address);
    static void cb_menu(Address, Address);

    void draw_circle();
    void draw_square();
    void draw_triangle();
    void draw_hexagon();
    void clear_shapes();

    void shapes_redraw(); //to call instead of Fl::redraw()
};
//EX 04--

//EX 06
struct Clock : Circle //static clock. No move() or size changes for now
{
    Clock(Point p, int r);
    void draw_lines() const;
    void set_time(int seconds);
    void increment_time(int seconds);
private:
    vector<Arrow*> arms; //first arm is hours, second arm is minutes, third arm is seconds. this moves dynamically with time
    Vector_ref<Text>numbers; //Pointer stuff introduced in chapter 17. Vector_ref sadly doesn't support clear() so I had to use pointers
    Lines lines;
    int current_seconds;
};
struct Clock_window : My_window {
	Clock_window(Point xy, int w, int h, const string& title ); 
    void update_clock(int seconds);
private:
	Clock clock;
    void run_clock();
};
//EX 06--

//EX 07
struct Airplane_window : My_window {
	Airplane_window(Point xy, int w, int h, const string& title ); 
    void move_plane();
private:
	Button start_button;
    Button stop_button;
    Image img;

	static void cb_start(Address, Address);
    static void cb_stop(Address, Address);
	void start();
    void stop();
    double direction;
};
//EX 07--

//EX 10
struct Function_window : My_window {
	Function_window(Point xy, int w, int h, const string& title ); 
private:
    vector<Function*>shapes; //Pointer stuff introduced in chapter 17. Only used because I really wanted to have a clear_shapes()
    In_box range; // Should've probably used Vector_ref instead but this didn't allow me to clear the vector
    In_box origin_point;
    In_box origin_point_2;
    Menu menu;
    Button menu_button;
    Button clear_button;

    void hide_menu() {menu.hide(); menu_button.show();}

    void sin_pressed() {draw_sin();hide_menu();}
    void cos_pressed() {draw_cos();hide_menu();}
    void tan_pressed() {draw_tan();hide_menu();}
    void log_pressed() {draw_log();hide_menu();}
    void clear_pressed() {clear_shapes();}
    void menu_pressed() {menu_button.hide(); menu.show();}
	
	static void cb_sin(Address, Address);
    static void cb_cos(Address, Address);
    static void cb_tan(Address, Address);
    static void cb_log(Address, Address);
    static void cb_clear(Address, Address);
    static void cb_menu(Address, Address);

    void draw_sin();
    void draw_cos();
    void draw_tan();
    void draw_log();
    void clear_shapes();

    void shapes_redraw(); //to call instead of Fl::redraw()

    Axis x_axis;
    Axis y_axis;
};
//EX 10--