//g++ -w -Wall -std=c++11 ../sourcesgui/Graph.cpp ../sourcesgui/Window.cpp ../sourcesgui/GUI.cpp '../sourcesgui/Simple_window.cpp' ../CHAPTER13/sources.cpp ../CHAPTER14/sources.cpp ../CHAPTER15/sources.cpp sources.cpp  C16EXX.cpp `fltk-config --ldflags --use-images` -o C16EXX

#include "./sources.h"

//EX 01
My_window::My_window(Point xy, int w, int h, const string& title) :
    Window{xy,w,h,title},
    next_button{Point{x_max()-70,0}, 70, 20, "Next", cb_next},
    quit_button{Point{x_max()-70,20}, 70, 20, "Quit", cb_quit},
    next_pushed{false},
    quit_pushed{false}
{
    attach(next_button);
    attach(quit_button);
}

//------------------------------------------------------------------------------

void My_window::wait_for_button()

{
    while(!next_pushed && !quit_pushed) Fl::wait();
    if(next_pushed)
    {
        next_pushed = false;
        Fl::redraw();
    }
}

//------------------------------------------------------------------------------

void My_window::cb_next(Address, Address pw)
{  
    reference_to<My_window>(pw).next();    
}

void My_window::cb_quit(Address, Address pw)
{  
    reference_to<My_window>(pw).quit();    
}

//------------------------------------------------------------------------------

void My_window::next()
{
    next_pushed = true;
}

void My_window::quit()
{
    quit_pushed = true;
    hide();
}
//------------------------------------------------------------------------------
//EX 01--

//EX 02
Checkerboard_window::Checkerboard_window(Point xy, int w, int h, const string& title)
    :   My_window{xy,w,h,title},
        button1{Point{x_max()/2-75,y_max()/2-75}, 50, 50, "1", cb_1},
        button2{Point{x_max()/2-25,y_max()/2-75}, 50, 50, "2", cb_2},
        button3{Point{x_max()/2+25,y_max()/2-75}, 50, 50, "3", cb_3},
        button4{Point{x_max()/2+75,y_max()/2-75}, 50, 50, "4", cb_4},
        button5{Point{x_max()/2-75,y_max()/2-25}, 50, 50, "5", cb_5},
        button6{Point{x_max()/2-25,y_max()/2-25}, 50, 50, "6", cb_6},
        button7{Point{x_max()/2+25,y_max()/2-25}, 50, 50, "7", cb_7},
        button8{Point{x_max()/2+75,y_max()/2-25}, 50, 50, "8", cb_8},
        button9{Point{x_max()/2-75,y_max()/2+25}, 50, 50, "9", cb_9},
        button10{Point{x_max()/2-25,y_max()/2+25}, 50, 50, "10", cb_10},
        button11{Point{x_max()/2+25,y_max()/2+25}, 50, 50, "11", cb_11},
        button12{Point{x_max()/2+75,y_max()/2+25}, 50, 50, "12", cb_12},
        button13{Point{x_max()/2-75,y_max()/2+75}, 50, 50, "13", cb_13},
        button14{Point{x_max()/2-25,y_max()/2+75}, 50, 50, "14", cb_14},
        button15{Point{x_max()/2+25,y_max()/2+75}, 50, 50, "15", cb_15},
        button16{Point{x_max()/2+75,y_max()/2+75}, 50, 50, "16", cb_16},
        random_box{Point{0,0},100,20,"random output: "}
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
    attach(button13);
    attach(button14);
    attach(button15);
    attach(button16);
    attach(random_box);
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
void Checkerboard_window::cb_13(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).thirteen();    
}
void Checkerboard_window::cb_14(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).fourteen();    
}
void Checkerboard_window::cb_15(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).fifteen();    
}
void Checkerboard_window::cb_16(Address, Address pw)
{  
    reference_to<Checkerboard_window>(pw).sixteen();    
}

//------------------------------------------------------------------------------

void Checkerboard_window::one() //hide two
{
    button2.hide();
}

void Checkerboard_window::two() //hide one
{
    button1.hide();
}

void Checkerboard_window::three() //reset hide and color
{
    button1.show();
    button2.show();
}
void Checkerboard_window::four() //turn row into random colors
{
    //Author suggests color change but not sure how to achieve this
}

void Checkerboard_window::five() 
{
    button5.move(rand()%x_max(),rand()%y_max());
}

void Checkerboard_window::six() //reset hide
{
    random_box.put(button6.loc.x);
}
void Checkerboard_window::seven() //weird pointer thing
{
    int abc ;
    int* ptr = &abc;
    random_box.put(to_string(ptr));
}

void Checkerboard_window::eight() 
{
    random_box.move(rand()%x_max(),rand()%y_max());
}
void Checkerboard_window::nine() //reset hide
{
    //do things
}
void Checkerboard_window::ten() //hide two
{
    //do things
}
void Checkerboard_window::eleven() //hide one
{
    //do things
}
void Checkerboard_window::twelve() //reset hide
{
    //do things
}
void Checkerboard_window::thirteen() //reset hide
{
    //do things
}
void Checkerboard_window::fourteen() //hide two
{
    //do things
}

void Checkerboard_window::fifteen() //hide one
{
    //do things
}

void Checkerboard_window::sixteen() //reset hide
{
    //do things
}
//------------------------------------------------------------------------------
//EX 02--

//EX 03
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

void Image_window::click() //hide two
{
    pair<double,double> coords (rand()%(x_max()-button.width)-button.loc.x,rand()%(y_max()-button.height)-button.loc.y); 
    button.move(coords.first,coords.second);
    img.move(coords.first,coords.second);
}
//EX 03--

//EX 04
Shapes_window::Shapes_window(Point xy, int w, int h, const string& title) :
    My_window(xy,w,h,title),
    next_x{{20,0},50,20,"X"},
    next_y{{20,20},50,20,"Y"},
    width_box{{125,0},50,20,"Width"},
    height_box{{125,20},50,20,"Height"},
    menu{{x_max()-70,40},70,20,Menu::vertical,"Shapes"},
    menu_button{{x_max()-70,40},70,20,"Shapes",cb_menu},
    clear_button{{x_max()-140,40},70,20,"Clear",cb_clear}
{
    attach(next_x);
    attach(next_y);
    attach(width_box);
    attach(height_box);

    menu.attach(new Button{{0,0},0,0,"Circle",cb_circle});
    menu.attach(new Button{{0,0},0,0,"Square",cb_square});
    menu.attach(new Button{{0,0},0,0,"Triangle",cb_triangle});
    menu.attach(new Button{{0,0},0,0,"Hexagon",cb_hexagon});
    attach(menu);

    menu.hide();
    attach(menu_button);
    attach(clear_button);
}

void Shapes_window::cb_circle(Address, Address pw)
{  
    reference_to<Shapes_window>(pw).circle_pressed();    
}
void Shapes_window::cb_square(Address, Address pw)
{  
    reference_to<Shapes_window>(pw).square_pressed();    
}
void Shapes_window::cb_triangle(Address, Address pw)
{  
    reference_to<Shapes_window>(pw).triangle_pressed();    
}
void Shapes_window::cb_hexagon(Address, Address pw)
{  
    reference_to<Shapes_window>(pw).hexagon_pressed();    
}
void Shapes_window::cb_clear(Address, Address pw)
{  
    reference_to<Shapes_window>(pw).clear_pressed();    
}
void Shapes_window::cb_menu(Address, Address pw)
{  
    reference_to<Shapes_window>(pw).menu_pressed();    
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
        shapes.push_back(new Ellipse{Point{x,y},width/2,height/2});
    }
    else{ 
        shapes.push_back(new Circle{Point{x,y},width/2});
    }
    shapes_redraw();
}
void Shapes_window::draw_square() 
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    int width {width_box.get_int()};
    int height {height_box.get_int()};

    shapes.push_back(new Rectangle{Point{x,y},width,height});

    shapes_redraw();
}

void Shapes_window::draw_triangle() 
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    int width {width_box.get_int()}; //not the real width. Couldn't afford to waste time with details
    int height {height_box.get_int()};


    shapes.push_back(new Regular_polygon{Point{x,y},width/2,3});

    shapes_redraw();
}

void Shapes_window::draw_hexagon() 
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    int width {width_box.get_int()}; //not the real width. Couldn't afford to waste time with details
    int height {height_box.get_int()};

    shapes.push_back(new Regular_hexagon{Point{x,y},width/2});

    shapes_redraw();
}

void Shapes_window::clear_shapes() 
{
    for (Shape* sh : shapes)
    {
        detach(*sh);
        delete sh;  //Pointer clean up (see Chapter 17)
    }

    shapes.clear();

    shapes_redraw();
}

void Shapes_window::shapes_redraw()
{
    for (Shape* sh : shapes)
    {
        attach(*sh);
    }

    redraw();
}
//EX 04--

//EX 06
Clock::Clock(Point p, int r)
    : Circle{p,r}, current_seconds{0}
{
    const int N {12};
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 1; i <= N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * -i + (PI);
        numbers.push_back(new Text{Point{sin(radangle)*r*8/10+p.x,cos(radangle)*r*8/10+p.y},to_string(i)});
        lines.add(Point{sin(radangle)*r+p.x-sin(radangle+PI)*r/20,cos(radangle)*r+p.y-cos(radangle+PI)*r/20},Point{sin(radangle)*r+p.x+sin(radangle+PI)*r/20,cos(radangle)*r+p.y+cos(radangle+PI)*r/20});
    }
    arms.push_back(new Arrow{Circle::center(),Point{cos(3*PI/2)*(Circle::radius()*1/3)+Circle::center().x,sin(3*PI/2)*(Circle::radius()*1/3)+Circle::center().y}}); //hours
    arms.push_back(new Arrow{Circle::center(),Point{cos(3*PI/2)*(Circle::radius()*2/3)+Circle::center().x,sin(3*PI/2)*(Circle::radius()*2/3)+Circle::center().y}}); //minutes
    arms.push_back(new Arrow{Circle::center(),Point{cos(3*PI/2)*Circle::radius()+Circle::center().x,sin(3*PI/2)*Circle::radius()+Circle::center().y}}); //seconds
}

void Clock::increment_time(int seconds)
{
    if(seconds<1) error("wrong argument on increment_time()");
    seconds+=current_seconds;
    set_time(seconds);
}

void Clock::set_time(int seconds)
{
    if(seconds<0) error("wrong argument on set_time()");
    const int seconds_in_12_hours {12*60*60};
    const int seconds_in_60_minutes {60*60};
    current_seconds=seconds;
    while(current_seconds>seconds_in_12_hours)current_seconds-=seconds_in_12_hours;

    double hourangle {current_seconds*2*PI/seconds_in_12_hours+ (3*PI/2)};
    int hour = floor(current_seconds/seconds_in_60_minutes);
    int minutes = floor((current_seconds-hour*seconds_in_60_minutes)/60);
    //int second = floor((current_seconds-hour*60*60-minutes*60));
    //cout<<hour<<'-'<<minutes<<'-'<<second;
    double minuteangle {(current_seconds-hour*seconds_in_60_minutes)*2*PI/seconds_in_60_minutes+ (3*PI/2)};
    double secondangle {(current_seconds-hour*seconds_in_60_minutes-minutes*60)*2*PI/60+ (3*PI/2)};

    for (Arrow* ar : arms)
    {
        delete ar;  //Pointer clean up (see Chapter 17)
    }
    arms.clear();
    arms.push_back(new Arrow{Circle::center(),Point{cos(hourangle)*(Circle::radius()*1/3)+Circle::center().x,sin(hourangle)*(Circle::radius()*1/3)+Circle::center().y}});
    arms.push_back(new Arrow{Circle::center(),Point{cos(minuteangle)*(Circle::radius()*2/3)+Circle::center().x,sin(minuteangle)*(Circle::radius()*2/3)+Circle::center().y}});
    arms.push_back(new Arrow{Circle::center(),Point{cos(secondangle)*Circle::radius()+Circle::center().x,sin(secondangle)*Circle::radius()+Circle::center().y}});
}

void Clock::draw_lines() const
{
    Circle::draw_lines();
    lines.draw_lines();
    for (int i = 0 ; i<numbers.size();i++)
    {
        numbers[i].draw_lines();
    }
    for (int i = 0 ; i<arms.size(); i++)
    {
        arms[i]->draw_lines(); //See chapter 17 for reference
    }
}

Clock_window::Clock_window(Point xy, int w, int h, const string& title )
    : My_window{xy,w,h,title},
      clock{{x_max()/2,y_max()/2},(x_max() < y_max()) ? x_max()/2-x_max()/40 : y_max()/2-y_max()/40}
{
    time_t current_time = time(NULL);
    tm* time_c = localtime(&current_time);
    int seconds_since_0 = time_c->tm_hour*3600 + time_c->tm_min*60 + time_c->tm_sec; //seconds since midnight or midday
    clock.set_time(seconds_since_0);
    attach(clock);
    run_clock();
}

void Clock_window::update_clock(int seconds)
{
    clock.increment_time(seconds);
    redraw();
}
//reference: https://codereview.stackexchange.com/questions/111101/a-simple-analog-clock-using-fltk
void timer_callback(void* window){
    reinterpret_cast<Clock_window*>(window)->update_clock(1);
    Fl::repeat_timeout(1, timer_callback, window);
}

void Clock_window::run_clock () {
    Fl::add_timeout(1, timer_callback, this);
}
//------------
//EX 06--

//EX 07
Airplane_window::Airplane_window(Point xy, int w, int h, const string& title) :
    My_window(xy,w,h,title),
    start_button(Point(0,0), 50, 50, "Start", cb_start),
    stop_button(Point(0,50), 50, 50, "Stop", cb_stop),
    img{Point(x_max()/2,y_max()/2),"airplane.jpg"},
    direction {randint(0,360)*PI/180.0}
{
    attach(start_button);
    attach(stop_button);
    attach(img);
}

void Airplane_window::cb_start(Address, Address pw)
{  
    reference_to<Airplane_window>(pw).start();    
}
void Airplane_window::cb_stop(Address, Address pw)
{  
    reference_to<Airplane_window>(pw).stop();    
}

void Airplane_window::move_plane()
{
    const int airplane_x_size {49};//hardcoded img size
    const int airplane_y_size {43};
    pair<double,double> coords (cos(direction)*randint(3,8),sin(direction)*randint(3,8)); 
    while(coords.first+img.point(0).x>x_max()-airplane_x_size || coords.second+img.point(0).y>y_max()-airplane_y_size || 
    coords.first+img.point(0).x<0 || coords.second+img.point(0).y<0)
    {
        //get new direction
        direction = randint(0,360)*PI/180.0;
        coords.first=cos(direction)*randint(3,8);
        coords.second=sin(direction)*randint(3,8);
    }
    img.move(coords.first,coords.second);
    redraw();
}

void timer_plane_callback(void* window){
    reinterpret_cast<Airplane_window*>(window)->move_plane();
    Fl::repeat_timeout(0.1, timer_plane_callback, window);
}
void Airplane_window::stop()
{
    Fl::remove_timeout(timer_plane_callback, this);
}
void Airplane_window::start() 
{
    Fl::add_timeout(0.1, timer_plane_callback, this);
}
//EX 07--