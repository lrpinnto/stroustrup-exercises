//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' ../CHAPTER13/sources.cpp ../CHAPTER14/sources.cpp sources.cpp  C15EXX.cpp `fltk-config --ldflags --use-images` -o C15EXX

#include "../CHAPTER14/sources.h"

//Weird hack I had to come up with to allow Lambda expressions with capture within functions
//Use FunctionLambda instead of Function if your Function uses Lambda expressions
typedef std::function<double (double)> Fct2; //Fix for C15E05.cpp see https://groups.google.com/g/ppp-public/c/WBHYlwS6m3g

struct FunctionLambda : Shape {
	// the function parameters are not stored
	FunctionLambda(Fct2 f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25);
	//Function(Point orig, Fct f, double r1, double r2, int count, double xscale = 1, double yscale = 1);	
};