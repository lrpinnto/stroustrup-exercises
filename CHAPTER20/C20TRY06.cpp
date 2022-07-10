//CHAPTER 20 TRY 06

#include <vector>
#include <iostream>
using namespace std;

template<typename Iter>
void advance(Iter& p, int n)
{
    while(0<n)
    {
        ++p;
        --n;
    }
    while(0>n)
    {
        --p;
        ++n;
    }
}

int main()
{
    vector<int> abc {0,1,2,3,4,5,6,7,8,9};
    int* p {&abc[5]};
    cout<<*p<<'\n'<<"5-3=";
    advance(p,-3);
    cout<<*p<<'\n'<<"2+7=";
    advance(p,7);
    cout<<*p<<'\n';
}