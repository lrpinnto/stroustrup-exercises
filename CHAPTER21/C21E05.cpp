// CHAPTER 21 EX 05

// Redesign and re-implement find() and count() to take iterators to the first and last elements. Compare the results to the standard versions.

// Count already returns an int by default. Not sure what is being requested.

#include <vector>
#include <iostream>

template<typename Iter, typename T>
bool find(Iter& first, Iter last, const T& val)
{
    while (first != last) {
        if (*first == val)
            return true;
        ++first;
    }
    return false;
}

int main()
{
    srand(time(0));
    std::vector<int> b {1,2,3,4,5,6,7,8,9};
    auto p {b.begin()};
    if(find(p,b.end(),rand()%9)) std::cout<<*p<<':'<<&(*p)<<'\n';
    else std::cout<<"Val not found.\n";
}