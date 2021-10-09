//CHAPTER 16 EX 06

#include "./sources.h" 
#ifdef _WIN32 //if Windows OS get sleep() from Windows.h
#include <Windows.h>
#else //else, get it from unistd.h
#include <unistd.h> 
#endif
#include <time.h>  //clocks() 
#include <ctime>  
#include <chrono>

struct Clock : Circle //static clock. No move() or size changes for now
{
    Clock(Point p, int r);
    void draw_lines() const;
    //void set_time(int hours, int minutes, int seconds);
    void set_time(int seconds);
    void increment_time(int seconds);
private:
    vector<Arrow*> arms; //first arm is hours, second arm is minutes, third arm is seconds. this moves dynamically with time
    Vector_ref<Text>numbers; //Pointer stuff introduced in chapter 17. Vector_ref sadly doesn't support clear() so I had to use pointers
    Lines lines;
    int current_seconds;
};

Clock::Clock(Point p, int r)
    : Circle{p,r}, current_seconds{0}
{
    const int N {12};
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 1; i <= N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * -i + (PI);
        numbers.push_back(new Text{Point{sin(radangle)*r*9/10+p.x,cos(radangle)*r*9/10+p.y},to_string(i)});
        //lines.add(Point{sin(radangle)*r+p.x-cos(radangle)*r/10,cos(radangle)*r*+p.y-sin(radangle)*r/10},Point{sin(radangle)*r+p.x+cos(radangle)*r/10,cos(radangle)*r*+p.y+sin(radangle)*r/10});
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
    int hour = floor(current_seconds/(60*60));
    int minutes = floor((current_seconds-hour*60*60)/60);
    //int second = floor((current_seconds-hour*60*60-minutes*60));
    //cout<<hour<<'-'<<minutes<<'-'<<second;
    double minuteangle {(current_seconds-hour*60*60)*2*PI/seconds_in_60_minutes+ (3*PI/2)};
    double secondangle {(current_seconds-hour*60*60-minutes*60)*2*PI/60+ (3*PI/2)};

    for (Arrow* ar : arms)
    {
        delete ar;  //Pointer clean up (see Chapter 17)
    }
    arms.clear();
    arms.push_back(new Arrow{Circle::center(),Point{cos(hourangle)*(Circle::radius()*1/3)+Circle::center().x,sin(hourangle)*(Circle::radius()*1/3)+Circle::center().y}});
    arms.push_back(new Arrow{Circle::center(),Point{cos(minuteangle)*(Circle::radius()*2/3)+Circle::center().x,sin(minuteangle)*(Circle::radius()*2/3)+Circle::center().y}});
    arms.push_back(new Arrow{Circle::center(),Point{cos(secondangle)*Circle::radius()+Circle::center().x,sin(secondangle)*Circle::radius()+Circle::center().y}});
}

/*void Clock::set_time(int hours, int minutes, int seconds)
{
    if(hours<0 || hours>12 || minutes <1 || minutes > 60 || seconds < 1 || seconds > 60) error("incorrect arguments on set_time()");
    current_seconds = hours*60+minutes*60+seconds;
    double smallest_hour_division {2*PI/12};
    double smallest_minute_division {2*PI/60};
    double smallest_second_division {2*PI/(60)};

    double hourangle = smallest_hour_division * hours + (3*PI/2);
    double minuteangle = smallest_minute_division * minutes + (3*PI/2);
    double secondangle = smallest_second_division * seconds + (3*PI/2);

    for (Arrow* ar : arms)
    {
        delete ar;  //Pointer clean up (see Chapter 17)
    }
    arms.clear();
    arms.push_back(new Arrow{Circle::center(),Point{cos(hourangle)*(Circle::radius()*1/3)+Circle::center().x,sin(hourangle)*(Circle::radius()*1/3)+Circle::center().y}});
    arms.push_back(new Arrow{Circle::center(),Point{cos(minuteangle)*(Circle::radius()*2/3)+Circle::center().x,sin(minuteangle)*(Circle::radius()*2/3)+Circle::center().y}});
    arms.push_back(new Arrow{Circle::center(),Point{cos(secondangle)*Circle::radius()+Circle::center().x,sin(secondangle)*Circle::radius()+Circle::center().y}});
}*/

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

struct Clock_window : My_window {
	Clock_window(Point xy, int w, int h, const string& title ); 
    void update_clock(int seconds);
private:
	Clock clock;
    Image img; //weird frame
    void run_clock();
};

Clock_window::Clock_window(Point xy, int w, int h, const string& title )
    : My_window{xy,w,h,title},
      clock{{200,200},100},
      img{{200,200},"someimage.jpg"}
{
    /*auto now = chrono::current_zone()->to_local(chrono::system_clock::now());
    auto today = floor<chrono::days>(now);
    auto tod = chrono::duration_cast<chrono::seconds>(now - today);*/
    clock.set_time(43190);
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
int main()
try
{
    Clock_window win {Point{100,100},600,400,"EX 06"};
    win.wait_for_button();
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
