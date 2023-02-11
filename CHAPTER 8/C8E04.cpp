#include "../stroustrup/std_lib_facilities.h"
#include "C802.cpp"
#include <climits>

//CAP 8 EXERCISE 4

void fibonacci(int x, int y, vector<int>& v, int n)
{
    v={x,y};
    while(v.size()<n)
    {
        v.push_back(v[v.size()-2]+v[v.size()-1]);
    }
}

class Negative_Number {};
class Overflow {};

int main()
{
    while(true) try
    {
        int x {0};
        int y {0};
        vector<int>v;

        cout<<"Enter 2 numbers:\n\tx->";
        cin>>x;
        if(x<=0) throw Negative_Number{};
        if(x==INT_MAX) throw Overflow{};
        cout<<"\ty->";
        cin>>y;
        if(y<=0) throw Negative_Number{};

        fibonacci(x,y,v,3);
        for (int n = 3; v[v.size()-1]>v[v.size()-2] ; n++)
        {
            fibonacci(x,y,v,n);
        }

        print("Fibbonaci sequence using given values:",v);
        cout<<"\nBest approximation: "<<v[v.size()-2]<<endl;

        return 0;
    }
    catch(Negative_Number) {
        cout << "Please use positive numbers.\n"; }
    catch(Overflow) {
        cout << "Please use a smaller number.\n"; cin.clear();}
    catch(...) {
        cout << "Exception: something went wrong.\n"; }
}