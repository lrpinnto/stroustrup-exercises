//CHAPTER 16 EX 05

#include "./sources.h" 

int main()
try
{
    constexpr int win_x {600};
    constexpr int win_y {400};
    cout<<"Please input coordinate pairs, separated by space";
    vector<pair<int,int>> coords;
    while(true)
    {
        pair<int,int> abc;
        cin>>abc;
        coords.push_back(abc);
    }
    My_window win {Point{100,100},win_x,win_y,"EX 05"};
    win.wait_for_button();
    Rectangle square {{0,0},40,40}; //random shape
    for (pair<int,int> p : coords)
    {
        square.move(p.first-square.point(0).x,p.second-square.point(0).y);
        win.wait_for_button();
    }
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
