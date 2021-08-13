//CHAPTER 13 EX 09

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 
    cout<<"Input the desired radius:";
    int r;
    cin>>r;
    int horizontal_distance_2_center {round(r*sin(45))};
    int half_length_vertical_side {round(r*cos(45))};
    Vector_ref<Regular_hexagon> rh;
    for (int j = 0; j*r < win_y; j++)
    {
        for (int i = 0; i*horizontal_distance_2_center < win_x; i++)
        {
            if(j%2==0)
            {
                rh.push_back(new Regular_hexagon{Point{horizontal_distance_2_center*2*i,j*(r+half_length_vertical_side)},r});
            }
            else
            {
                rh.push_back(new Regular_hexagon{Point{horizontal_distance_2_center*2*i+horizontal_distance_2_center,j*(r+half_length_vertical_side)},r});
            }
            win.attach(rh[rh.size()-1]);
        }
    }
    win.wait_for_button();
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