#include <vector>
#include <iostream>

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    for (T i; is>>i; ) v.push_back(i);
    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
    for(T& i : v) os<<i<<' ';
    return os;
}