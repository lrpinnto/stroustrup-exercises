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
};

class Control_shape : public Controller
{
private:
    Shape& shape;
public:
    Control_shape(Shape& shapee);
    void on() override;
    void off() override;
    void set_level(int l) override;
    void show() const override;
};

Control_shape(Shape& shapee)
    : shape{shapee}
{}

void on()
{
    shape.set_color();
}

int main()
{
    Controller_test ct;
    ct.set_level(20);
    ct.show();
    ct.on();
    ct.show();
    ct.get_level();
}
