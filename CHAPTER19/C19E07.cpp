//Chapter 19 EX 07

#include <vector>
#include <iostream>
#include "./Number.h"
using namespace std;

template<typename T, typename U>
Number<T>& operator+=(Number<T>& leftval, const Number<U>& rightval)
{
    int x=leftval.get();;
    x+=rightval.get();
    leftval=x;
    return leftval;
}

template<typename T, typename U>
int f(const vector<Number<T>>& vt, const vector<Number<U>>& vu) //this assumes multiplication with default constructors will always result in 0 (therefore picking the smallest vector)
{     
    Number<int> sum {0};
    for (int i = 0; i < (vt.size() > vu.size() ? vu.size() : vt.size()) ; i++) //Pick the smallest of the 2
    {
        sum+=vt[i]*vu[i];
    }
    return sum.get();
}

int main()
try {
    vector<Number<int>> a {1,2,3,4,5,6};
    vector<Number<char>> b {1,1,1,1,1}; //if vect size() b < a then f() adds b default constructor
    cout<<f(a,b);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}