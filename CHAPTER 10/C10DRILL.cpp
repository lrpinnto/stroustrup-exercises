#include "../stroustrup/std_lib_facilities.h"

//CHAP 10 DRILL

struct Point  //it's probably wiser to define a constructor for Point instead of doing all the checks inside operator>>
{
    double x;
    double y;
};

istream& operator>>(istream& is, Point& d)  //will not handle negatives
{
    double x, y;
    char ch,par1,par2;
    is>>par1;  //expect a parenthesis but it's optional
    if(par1=='(')
    {
        is.unget();
        is>>par1>>x>>ch>>y>>par2;
        if(!is) return is;
        if(ch!=',') is.clear(ios_base::failbit);
        if(par1!='(' || par2!=')') is.clear(ios_base::failbit);
        d.x=x;
        d.y=y;
    }
    else if (isdigit(par1))
    {
        is.unget();
        is>>x>>ch>>y;
        if(!is) return is;
        if(ch!=',') is.clear(ios_base::failbit);
        d.x=x;
        d.y=y;
    }

    else is.clear(ios_base::failbit); //probably not the correct usage
    
    
    return is;
}

bool operator==(const Point& a, const Point& b)  
{
    return a.x==b.x && a.y==b.y;
}

bool operator!=(const Point& a, const Point& b)  
{
    return !(a==b);
}

int main()
{
    cout<<"Please input 7 x,y pairs (with or without parentheses). Each separated by enter.\n";
    vector<Point>original_points;
    Point input_points;
    for (int i = 0; i < 7; i++)
    {
        cin>>input_points;
        original_points.push_back(input_points);
    }
    cout<<"Writing:\n";
    for (Point i : original_points)
    {
        cout<<'('<<i.x<<','<<i.y<<')'<<'\n';
    }
    
    ofstream ost {"mydata.txt"};
    if(!ost) error("can't open output file mydata.txt");

    for (Point i : original_points)
    {
        ost<<'('<<i.x<<','<<i.y<<')'<<'\n';
    } 
    ost.close();
    ifstream ist {"mydata.txt"};
    if(!ist) error("can't open output file mydata.txt");

    Point output_point;
    vector<Point>processed_points;

    while(ist>>output_point)
    {
        processed_points.push_back(output_point);
    }
    cout<<"Reading:\n";
    for (Point i : processed_points)
    {
        cout<<'('<<i.x<<','<<i.y<<')'<<'\n';
    }

    if (processed_points!=original_points) cout<<"Something's wrong!\n";
    
}
