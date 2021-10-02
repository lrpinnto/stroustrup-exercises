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