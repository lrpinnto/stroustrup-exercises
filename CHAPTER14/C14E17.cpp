//CHAPTER 14 EX 17

#include "./sources.h"
#include <stdexcept>

//REFERENCE: https://www.cs.uah.edu/~rcoleman/CS307/SelectedTopics/Exceptions.html

int main()
{
    int win_x {1600};
    int win_y {900};
    Point tl {100,100};
    Simple_window win {tl,win_x,win_y,"Window"}; 

    Text title {{900,10},"Exceptions"};
    Text sub_title {{900,100},"C++ Exception Classes"};
    Text topic {{100,200},"#include <stdexcept>"};
    //--
    Box_text one {{900,300},5,"exception"};
    //--
    Box_text two {{100,400},5,"bad_alloc"};
    Box_text three {{500,400},5,"logic_error"};
    Box_text four {{900,400},5,"runtime_error"};
    Box_text five {{1300,400},5,"bad_cast"};
    //--
    Box_text six {{100,500},5,"length_error"};
    Box_text seven {{100,600},5,"domain_error"};
    Box_text eight {{100,700},5,"out_of_range"};
    Box_text nine {{100,800},5,"invalid_argument"};
    Box_text ten {{1100,500},5,"range_error"};
    Box_text eleven {{1100,600},5,"overflow_error"};
    Box_text twelve {{1100,700},5,"underflow_error"};
}
