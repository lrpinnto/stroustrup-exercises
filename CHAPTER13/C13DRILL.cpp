//CHAPTER 13 DRILL

#include "../sourcesgui/Graph.h"
#include "../sourcesgui/Simple_window.h"
#include <stdexcept>

Point get_randsquare(int grid, int x_size, int y_size)
{
    return Point{grid*(rand()%(x_size/grid)),grid*(rand()%(y_size/grid))};
}

int main()
try
{
    Point tl {0,0};
    Simple_window win {tl,800,1000,"Window"}; 
    int x_size {800};
    int y_size {800};
    int x_grid {100};
    int y_grid {100};

    Lines grid;
    for (int x = x_grid; x < x_size; x+=x_grid)
        grid.add(Point{x,0},Point{x,y_size});

    for (int y = y_grid; y < y_size; y+=y_grid)
        grid.add(Point{0,y},Point{x_size,y});
    
    Vector_ref<Rectangle> vr;

    for (int i = 0; i < x_size/x_grid; i++)
    {
        vr.push_back(new Rectangle{Point{x_grid*i,y_grid*i},100,100});
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }
    
    Image img {Point{0,200},"image.jpg"};
    Image img2 {Point{200,0},"image.jpg"};
    Image img3 {Point{400,0},"image.jpg"};
    win.attach(img);
    win.attach(img2);
    win.attach(img3);
    win.wait_for_button();

    
    while(true)
    {
        Image mov_img {get_randsquare(x_grid,x_size,y_size),"image2.jpg"};
        win.attach(mov_img);
        win.set_label("Moving object");
        win.wait_for_button();
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
