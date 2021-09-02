//CHAPTER 14 EX 9

#include "./sources.h"
#include <stdexcept>

int main()
try
{
    int win_x {1000};
    int win_y {1000};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"};
    
    Vector_ref<Shape>black_tiles; //unable to create normal vector of Shape. probably because Shape(const Shape&) = delete;
    Vector_ref<Shape>white_tiles;
    Vector_ref<Shape>white_checkers;
    Vector_ref<Shape>black_checkers;
    int tile_length {win_x/8};
    for (int i = 0; i < 8; i+=2)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j%2==0)
            {
                if(j<4)
                {
                    white_checkers.push_back(
                        new Circle{{i*tile_length+tile_length/2,j*tile_length+tile_length/2},tile_length/2}
                    );
                }
                black_tiles.push_back(
                    new Rectangle{{i*tile_length,j*tile_length},tile_length,tile_length}
                );
                white_tiles.push_back(
                    new Rectangle{{(i+1)*tile_length,(j)*tile_length},tile_length,tile_length}
                );
            }
            else
            {
                black_tiles.push_back(
                    new Rectangle{{(i+1)*tile_length,j*tile_length},tile_length,tile_length}
                );
                white_tiles.push_back(
                    new Rectangle{{(i)*tile_length,(j)*tile_length},tile_length,tile_length}
                );
            }
        }
    }

    Group board_black{black_tiles};
    board_black.set_fill_color(Color::black);
    Group board_white{white_tiles};
    board_white.set_color(Color::invisible);
    Group checker{white_checkers};
    checker.set_fill_color(Color::white);
    
    win.attach(board_black);
    win.attach(board_white);
    win.attach(checker);
    
    win.wait_for_button();
    checker.move(0,125);
    win.wait_for_button();

    int rand_indx;
    for (int count = 0; count < 10; count++) //individual move test
    {
        rand_indx = rand()%(white_checkers.size());
        checker.move(0,tile_length,rand_indx);
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