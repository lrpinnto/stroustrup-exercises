//CHAPTER 13 EX 15

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    Point tl {100,100};
    Simple_window win {tl,1600,900,"Window"}; 
    int hleg, vleg;
    cout<<"Enter horizontal leg:";
    cin>>hleg;
    cout<<"Enter vertical leg:";
    cin>>vleg;

    Vector_ref<Right_triangle>rt;

    for (int i = 0; i < 1600; i+=hleg)
    {
        for (int j = 0; j < 900; j+=vleg)
        {
            rt.push_back(new Right_triangle{{i,j},hleg,vleg,0});
            rt.push_back(new Right_triangle{{i+hleg,j+vleg},hleg,vleg,180});
            rt[rt.size()-1].set_fill_color(rand()%255);
            rt[rt.size()-2].set_fill_color(rand()%255);
            rt[rt.size()-1].set_color(rand()%255);
            rt[rt.size()-2].set_color(rand()%255);
            rt[rt.size()-1].set_style(rand()%5);
            rt[rt.size()-2].set_style(rand()%5);
            win.attach(rt[rt.size()-1]);
            win.attach(rt[rt.size()-2]);
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