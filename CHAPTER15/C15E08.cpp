//CHAPTER 15 EX 8

#include "./sources.h"
#include <stdexcept>

class Scale
{
private:
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) :cbase{b}, vbase{vb}, scale{s} {}
    int operator(int v) const {return cbase + (v-vbase)*scale; }
};

struct Distribution
{
    int year, young, middle, old;
};

istream& operator>>(istream& is, Distribution& d)
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if(is >> ch1 >> dd.year
            >>ch2>>dd.young>>dd.middle>>dd.old
            >>ch3)
    {
        if (ch1!='(' || ch2!=':' || ch3!=')')
        {
            is.clear(ios_base::failbit);
            return is;
        }
        
    }
    else return is;
    d=dd;
    return is;
}

int main()
try
{
    string file_name {"input_data.txt"};
    ifstream ifs {file_name};
    if(!ifs) error("Can't open ",file_name);

    Open_polyline children;
    Open_polyline adults;
    Open_polyline aged;

    for (Distribution d; ifs>>d;)
    {
        if (d.year<base_year || end_year < d.year)
        {
            error("Year out of range");
        }
        if (d.young+d.middle+d.old!=100)
        {
            error("Percentages don't add up");
        }
        const int x = xs(d.year);
        children.add(Point{x,ys(d.young)});
        adults.add(Point{x,ys(d.middle)});
        aged.add(Point{x,ys(d.old)});
        
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
