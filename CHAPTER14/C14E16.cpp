//CHAPTER 14 EX 16

#include "./sources.h"
#include <stdexcept>

class Controller
{
protected:
    Controller(){}
//private:
    bool status{false};
    int level{0};
public:
    virtual void on() {status=true;}
    virtual void off() {status=false;}
    virtual void set_level(int l) {level=l;}
    virtual void show() const {cout<<status;}
};

class Controller_test : public Controller
{
public:
    void get_level() {cout<<level;}
    using Controller::show;
};

class Control_shape : public Controller //should not be able to use default constructor
{
private:
    Shape& shape1;
    int level_style{0};
public:
    void on() override {status=true;}
    void off() override {status=false;}
    Control_shape(Shape& shapee);
    void set_level(int l) override;
    void set_level_style(int l);
};

void Control_shape::on() {status=true; shape1.set_color(Color::visible);}
void Control_shape::off() {status=false; shape1.set_color(Color::invisible);}

void Control_shape::set_level_style(int l)
{
    level_style=l;
    shape1.set_style(level_style) //cast to enum?
}

void Control_shape::set_level(int l)
{
    level=l;
    shape1.set_color(level); //cast to enum?
}

Control_shape::Control_shape(Shape& shapee)
    : shape1{shapee} 
{
    if(shape1.color()::visibility == Color::visibility()) //check if invisible
    {
        status=false;
    }
    else status=true;
    level=int(shape1.color()); //check if level is private when inherited
    level_style=int(shape1.style());
}

int main()
{
    Controller_test ct;
    ct.set_level(20);
    ct.show();
    ct.on();
    ct.show();
    ct.get_level();

    //------

    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Circle c {{100,100},100};

    Control_shape cs {c};

    win.attach(c);
    win.wait_for_button();
    cs.set_level(3);
    cs.set_level_style(3);
    cs.show();
    win.wait_for_button();
    cs.off();
    win.wait_for_button();
}
