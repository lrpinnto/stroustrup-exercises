#include "../stroustrup/std_lib_facilities.h"
#include "C802.cpp"

//CAP 8 EXERCISE 3

void fibonacci(int x, int y, vector<int>& v, int n)
{
    v={x,y};
    while(v.size()<n)
    {
        v.push_back(v[v.size()-2]+v[v.size()-1]);
    }

}

int main()
{
    vector<int>abc={1,2,3,4};
    print("test",abc);
    fibonacci(1,2,abc,10);
    print("test vector changed",abc);
}