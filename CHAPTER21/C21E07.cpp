// CHAPTER 21 EX 07

// Write a binary search function for a vector<int>
// Write a binary search function for a list<string>

/* Algorithm 
Look at the middle element
If the element's value equals x, we found it!
If the element's value is less than x, any element with value x must be to the right, so we look at the right half (doing a binary search on that half)
If the value of x is less than the element's value, any element with value x must be to the left, so we look aat the left half (doing a binary search on that half)
If we have reached the last element (going left or right) without finding x, then there is no element with that value
*/

#include <vector>
#include <list>
#include <iostream>
#include "../CHAPTER20/vectoroperators.h"
#include "./search.h"
#include <algorithm>
#include <climits>

bool customCmp(int a, int b)
{
    return a % 10 < b % 10;
}

int main()
{
    srand(time(0));
    std::vector<int> v (50);
    for(auto& i : v) i=rand()%10000;
    std::sort(v.begin(),v.end());
    std::cout<<v<<"\n\n";
    std::cout<<"Input values to see if they exist\n";
    int val;
    for(int i = 0 ; std::cin>>val && i<5 ; i++)
        std::cout<<(search::binary_search(v.begin(),v.end(),val) ? "Exists!\n" : "Doesn't exist.\n");
    
    std::sort(v.begin(),v.end(),customCmp); //Sorts values according to their last digit
    std::cout<<v<<"\n\n";
    std::cout<<"Input values to see if they exist\n";
    int val2;
    for(int i = 0 ; std::cin>>val2 && i<5 ; i++)
        std::cout<<(search::binary_search(v.begin(),v.end(),val2,customCmp) ? "Exists!\n" : "Doesn't exist.\n");

    // Need to complete binary search for list
}