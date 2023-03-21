// CHAPTER 21 EX 04

// Implement count_if() yourself

#include <vector>
#include <iostream>

template<typename In, typename T, typename Pred>
int count_if(In first, In last, const T& val, Pred pred)
{
    int count {0};
    while(first!=last)
    {
        if(pred(*first)) count++; 
        first++;
    }
    return count;
}

int main()
{
    std::vector<int> a {1,2,3,4,5,6,7,8,9 }; //5 odd numbers
    std::cout<<count_if(a.begin(),a.end(),20,[](int x){return x%2;});
}