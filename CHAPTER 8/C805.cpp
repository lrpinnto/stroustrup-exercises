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

vector<int>reverse_fibo(const vector<int>& v)
{
    vector<int>vec=v;
    reverse(vec.begin(),vec.end());
    return vec;
}

void reverse_noret(vector<int>& v)
{
    reverse(v.begin(),v.end());
}

int main()
{
    vector<int>abc={1,2,3,4};
    print("test",abc);
    fibonacci(1,2,abc,10);
    print("test vector changed",abc);
    print("test reverse_fibo()",reverse_fibo(abc));
    reverse_noret(abc);
    print("test reverse_noret()",abc);
}