// CHAPTER 20 ex 11

// Given a list<int> as a (by-reference) parameter, make a vector<double> and copy the elements of the list into it. Verify that the copy was
// complete and correct. Then print the elements sorted in order of increasing value.

#include <list>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <cmath>

template<typename T>
std::vector<T> f(const std::list<T>& l)
{
    std::vector<T> v (l.size());
    std::copy(l.begin(),l.end(),v.begin());
    if(!std::equal(v.begin(),v.end(),l.begin())) throw std::runtime_error("Containers don't match");
    return v;
}

int main()
{
    srand(time(0));
    std::list<double> l (20);
    for (auto& i : l)
    {
        i=(rand()%100)+((rand()%1000)*std::pow(10,-3)); //fill list with random <100 ints
    }
    auto v {f(l)};
    std::sort(v.begin(), v.end());
    std::cout<<"list:\n";
    for(const auto& i : l) std::cout<<i<<' ';
    std::cout<<"\nvector:\n";
    for(const auto& i : v) std::cout<<i<<' ';
}