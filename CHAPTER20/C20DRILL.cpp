//CHAPTER 20 DRILL

#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h>

template<typename Iter1, typename Iter2>
Iter2 copyy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    if(f1==e1) return f2;
    Iter2 first {f2};
    Iter1 p {f1};
    while(p!=e1) //this essentially means that it copies the whole size of [f1:e1). even if f2 isnt that big
    {
        *first=*p;
        ++first;
        ++p;
    }
    return first;
}

int main()
{
    int arr[10] {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> vec {0,1,2,3,4,5,6,7,8,9};
    std::list<int> lis {0,1,2,3,4,5,6,7,8,9};

    int arr2[] {*arr};
    std::vector<int> vec2 {vec};
    std::list<int> lis2 {lis};

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
        arr[i]+=2;
    
    for (int& i : vec)
        i+=3;
    
    for (int& i : lis)
        i+=5;
        
    std::cout<<"Array:";
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
        std::cout<<arr[i]<<' ';
    std::cout<<'\n';
    std::cout<<"Vector:";
    for (int i : vec)
        std::cout<<i<<' ';
    std::cout<<'\n';
    std::cout<<"List:";
    for (int i : lis)
        std::cout<<i<<' ';
    std::cout<<'\n';
    //Should probably use auto here, but anyway
    __gnu_cxx::__normal_iterator<int*, std::vector<int> > pointer1 {copyy(arr,arr+sizeof(arr)/sizeof(int),vec.begin())}; //cant make it receive .begin() and .end() as arguments?
    int* pointer2 {copyy(lis.begin(),lis.end(),arr)};
    
    std::cout<<*(--pointer1); //tests to see if the pointers are points to a position beyond the last element
    std::cout<<'\n';
    std::cout<<*(--pointer2);
    std::cout<<'\n';
    
    auto abc {std::find(vec.begin(),vec.end(),3)};
    std::cout<<"The position of '3' inside the vector is "<<abc-vec.begin()<<'\n';

    auto def {std::find(lis.begin(),lis.end(),27)};

    if (def==lis.end())
    {
        std::cout<<"Not found\n";
    }
    else
    {
        //std::cout<<def-lis.begin();
    }
}