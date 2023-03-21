// CHAPTER 21 EX 03

// Implement count() yourself

#include <vector>
#include <iostream>

template<typename In, typename T>
int count(In first, In last, const T& val)
{
    int count {0};
    while(first!=last)
    {
        if(*first==val)  count++; 
        first++;
    }
    return count;
}

int main()
{
    std::vector<int> a(10,20);
    a.insert(a.end()-a.size()/2,5);
    std::cout<<count(a.begin(),a.end(),20);
}
