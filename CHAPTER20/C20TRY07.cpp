//CHAPTER 20 TRY 07 & 08

#include <vector>
#include <list>
#include <string.h>
#include <iostream>
#include <stdexcept>

using namespace std;

//unsure if this was the intended solution. Moving on

template<typename Iter>
int count_el(Iter first, Iter last)
{
    int count {0};
    for (auto p = first; p!=last; p++)
    {
        count++;
    }
    return count;
}

template<typename Iter>
int compare(Iter first, Iter last, const char s[])
{
    for (auto p = first; p!=last; p++)
    {
        if (*p>*s || !s ) return 1;
        else if(*p<*s) return -1;
        s++;
    }
    return 0;
}

template<typename Iter> //using the iterator approach...
void fn(Iter first, Iter last)
{
    cout<<"Number of elements: "<<count_el(first,last)<<endl;
    try
    {
        compare(first,last,"Hello")==0 ? cout<<"It matches!"<<endl : cout<<"It doesn't match."<<endl;
        compare(first,last,"Howdy")<0 ? cout<<"The array is less than Howdy."<<endl : cout<<"The array is more than Howdy."<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    constexpr char a[] {"Hello"};
    const vector<char> b {'H','e','l','l','o'};
    const list<char> c {'H','e','l','l','o'};
    const string d {"Hello"};

    fn(begin(a),end(a));
    fn(b.begin(),b.end());
    fn(c.begin(),c.end());
    fn(d.begin(),d.end());

    int e[] {1,2,3,4,5};
    vector<int> f {1,2,3,4,5};
    list<int> g {1,2,3,4,5};
    cout<<"============="<<endl;
    fn(begin(e),end(e));
    fn(f.begin(),f.end());
    fn(g.begin(),g.end());
}