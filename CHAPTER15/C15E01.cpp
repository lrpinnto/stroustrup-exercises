//CHAPTER 15 EX 01

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {600};
    int win_y {600};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Function graphs"}; 
    Axis x {Axis::Orientation::x,{100,300},400,20,"1==20 pixels"};
    Axis y {Axis::Orientation::y,{300,100},400,20,"1==20 pixels"};
    y.notches.set_color(Color::red);
    x.notches.set_color(Color::red);

    int fac_iterative(int n)
    {
        if(n==0) return 1;
        else
        {
            int result;
            while(n>0)
            {  
                result*=n;
                n--;
            }
            return result;
        }
    }

    int fac(int n) {return n>1 ? n*fac(n-1) : 1; };
    Function fac1 { fac ,-10,11,{300,300},400,20,20};
    win.attach(fac1);
    win.wait_for_button();
    Function fac2 {fac_iterative,-10,11,{300,300},400,20,20};
    win.attach(fac2);
    win.wait_for_button();

    for (int i = 0; i <= 20; i++)
    {
        if(fac_iterative(i)!=fac(i)) error("functions don't match on "+ to_string(i));
    }
    
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
catch(...)
{
    // some more error reporting
    return 2;
}
