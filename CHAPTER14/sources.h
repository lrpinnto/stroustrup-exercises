//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' ../CHAPTER13/sources.cpp sources.cpp  C14E01.cpp `fltk-config --ldflags --use-images` -o C14E01

#include "../CHAPTER13/sources.h"

//EX 04
//Delete virtual function from a derived class
/*The best solution I have found so far to get a compile-time error when calling Ds method is by using a static_assert with a generic struct that inherits from false_type. 
As long as noone ever calls the method, the struct stays undefied and the static_assert won't fail.

If the method is called however, the struct is defined and its value is false, so the static_assert fails.

If the method is not called, but you try to call it on a pointer of the super class, then Ds method is not defined and you get an undefined reference compilation error.*/
//Reference: https://stackoverflow.com/questions/24609872/delete-virtual-function-from-a-derived-class

struct Immobile_Circle : Circle
{
    using Circle::Circle;
private:
    using Circle::move;  //The first would be to use using to change the visibility of the method to private, thus preventing others from using it. 
};                         //The problem with that solution is, that calling the method on a pointer of the super-class does not result in a compilation error.
//EX 04----

//EX 05
struct Striped_rectangle : Rectangle
{
    using Rectangle::Rectangle;
    void draw_lines() const;
};
//EX 05----

//EX 06
struct Striped_circle : Circle
{
    using Circle::Circle;
    void draw_lines() const;
};

int mod(int x);
//EX 06---