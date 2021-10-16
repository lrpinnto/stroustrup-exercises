//CHAPTER 16 EX 05

#include "./sources.h" 

struct pairs
{
    int first() const {return a;}
    int second() const {return b;}
    void set_first(int first) {a=first;}
    void set_second(int second) {b=second;}
private:
    int a;
    int b;
};

istream& operator>>(istream& is, pairs& p)
{
    int a,b;
    cin>>a>>b;
    p.set_first(a);
    p.set_second(b);
    return is;
}

int main()
try
{
    constexpr int win_x {600};
    constexpr int win_y {400};
    cout<<"Please input coordinate pairs, separated by space\n";
    vector<pairs> coords;
    pairs abc;
    while(cin>>abc) coords.push_back(abc);
    My_window win {Point{100,100},win_x,win_y,"EX 05"};
    Rectangle square {{0,0},40,40}; //random shape
    win.attach(square);
    for (pairs p : coords)
    {
        square.move(p.first()-square.point(0).x,p.second()-square.point(0).y);
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
