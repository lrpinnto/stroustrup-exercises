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