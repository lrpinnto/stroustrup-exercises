#include "./my.h"

int main()
{
    int x = 7;
    int y = 9;
    swap_r(x, y);
    swap_v(7, 9);
    const int cx = 7;
    const int cy = 9;
    //swap_vr(cx, cy);
    swap_v(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    //swap_vr(dx, dy);
    swap_v(7.7, 9.9);

    print(x); 
    print(y);
    print(cx); 
    print(cy); 
    print(dx); 
    print(dy);
}