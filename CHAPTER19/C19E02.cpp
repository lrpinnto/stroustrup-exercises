//Chapter 19 EX 02

#include <vector>
#include <iostream>
using namespace std;

template<typename T, typename U>
int f(const vector<T>& vt, const vector<U>& vu) //this assumes multiplication with default constructors will always result in 0 (therefore picking the smallest vector)
{     
    int sum {0};
    for (int i = 0; i < (vt.size() > vu.size() ? vu.size() : vt.size()) ; i++) //Pick the smallest of the 2
    {
        sum+=vt[i]*vu[i];
    }
    return sum;
}

int main()
try {
    vector<int> a {1,2,3,4,5,6};
    vector<char> b {1,1,1,1,1}; //if vect size() b < a then f() adds b default constructor
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