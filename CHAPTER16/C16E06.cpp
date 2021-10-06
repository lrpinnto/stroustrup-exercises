//CHAPTER 16 EX 06

#include "./sources.h" 
#ifdef _WIN32 //if Windows OS get sleep() from Windows.h
#include <Windows.h>
#else //else, get it from unistd.h
#include <unistd.h> 
#endif
#include <time.h>  //clocks() 

//https://www.cplusplus.com/reference/ctime/clock/
//https://www.softwaretestinghelp.com/cpp-sleep/

struct Clock : Circle //static clock. No move() or size changes for now
{
    Clock(Point p, int r);
    void draw_lines() const;
private:
    vector<Arrow> arms(3); //first arm is hours, second arm is minutes, third arm is seconds. this moves dynamically with time
    vector<Text>numbers;
    Lines lines;
    void set_time();
};

Clock::Clock(Point p, int r)
    : Circle{p,r}
{
    const int N {12};
    double smallest_rad_division = 2*PI/N; //dividing full circle into N amount of points
    for (int i = 1; i <= N; i++) //go through all rad angles of the full circle
    {
        double radangle = smallest_rad_division * i + (3*PI/2);
        numbers.push_back(Text{Point{sin(radangle)*r+p.x,cos(radangle)*r+p.y},to_string(i)});
        lines.add();
    }
    //set arms to a default position
}

void Clock::set_time(int hours, int minutes, int seconds)
{
    if(hours<1 || hours>12 || minutes <1 || minutes > 60 || seconds < 1 || seconds > 60) error("incorrect arguments on set_time()");
    double smallest_hour_division {2*PI/12};
    double smallest_minute_division {2*PI/60};
    double smallest_second_division {2*PI/(60)};

    double hourangle = smallest_hour_division * hours + (3*PI/2);
    double minuteangle = smallest_minute_division * minutes + (3*PI/2);
    double secondangle = smallest_second_division * seconds + (3*PI/2);

    arm[0]=Arrow{Circle::center(),Point{cos(hourangle)*(Circle::radius()*1/3),sin(hourangle)*(Circle::radius()*1/3)}};
    arm[1]=Arrow{Circle::center(),Point{cos(minuteangle)*(Circle::radius()*2/3),sin(hourangle)*(Circle::radius()*2/3)}};
    arm[2]=Arrow{Circle::center(),Point{cos(secondangle)*Circle::radius(),sin(secondangle)*Circle::radius()}};
}

void draw_lines()
{
    lines.draw_lines();
    for (Text& t : numbers)
    {
        t.draw_lines();
    }
    for (Arrow& a : arms)
    {
        a.draw_lines();
    }
}

struct Clock_window : My_window {
	Clock_window(Point xy, int w, int h, const string& title ); 
private:
	Clock clock;
    Image img; //weird frame
    Button clock_tick;
	
	static void cb_clock_tick(Address, Address);
	void click();
};

Clock_window::Clock_window(Point xy, int w, int h, const string& title )
    : clock{{200,200},w/2},
      img{{200,200},"someimage.jpg"},
      clock_tick{{0,0},0,0,"tick",cb_clock_tick}
{
    clock_tick.hide();
}

Clock_window::cb_clock_tick(Address, Address pw)
{
    reference_to<Checkerboard_window>(pw).update_clock(); 
}

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
