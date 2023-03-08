//CHAPTER 20 EX 20

#include <chrono>
#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
using namespace std;

template<typename T>
void benchmark(T& container, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x {rand()%INT_MAX};
        auto iter {lower_bound(container.begin(),container.end(),x)};
        container.insert(iter,x);
    }
}

int main()
{
    srand(time(0));
    int n {100000}; 
    auto t1 {chrono::system_clock::now()}; //start timer
    vector<int> v;
    benchmark(v,n);
    auto t2 {chrono::system_clock::now()}; //end timer

    cout<<"vector " << n << " times took "
        <<chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds\n"
        <<"first val: "<<v.front()<<'\t'<<"last val: "<<v.back()<<'\n';

    cout<<"#################\n";

    auto t3 {chrono::system_clock::now()}; //start timer
    list<int> l;
    benchmark(l,n);
    auto t4 {chrono::system_clock::now()}; //end timer

    cout<<"list " << n << " times took "
        <<chrono::duration_cast<chrono::milliseconds>(t4-t3).count() << " milliseconds\n"
        <<"first val: "<<l.front()<<'\t'<<"last val: "<<l.back()<<'\n';    
}

/*
My results:
vector 100000 times took 288 milliseconds
first val: 16019        last val: 2147476701
#################
list 100000 times took 108426 milliseconds
first val: 4891 last val: 2147479587
*/