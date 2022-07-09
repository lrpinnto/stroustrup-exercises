//CHAPTER 20 TRY 03

#include <iostream>

void copy(int* f1, int* e1, int* f2)
{
    int* first {f2};
    int* last {f2+(e1-f1)}; //this essentially means that it copies the whole size of [f1:e1). even if f2 isnt that big
    int* p {f1};
    while(first!=last) 
    {
        *first=*p;
        ++first;
        ++p;
        //if(p==e1) p=f1; //if iterator reaches the end of the first array, start over. Shouldn't happen ever.
    }
}

int main()
{
    int arr1[] {1,2,3};
    int arr2[] {6,7,8,9,0,0,0,0,0};
    copy(&(arr1[0]),&(arr1[2+1]),&(arr2[0]));
    std::cout<<"arr2:";
    for (int i = 0; i < sizeof(arr2)/sizeof(int); i++)
    {
        std::cout<<arr2[i]; //Should only copy 1,2,3 since that's the whole size of the array and what we set as the "end" of the iterator
    }
    std::cout<<'\n'<<"arr4:";
    int arr3[] {1,2,3,4,5,6,7,8,9};
    int arr4[] {1};
    copy(&(arr3[0]),&(arr3[8+1]),&(arr4[0]));
    for (int i = 0; i < sizeof(arr3)/sizeof(int); i++)
    {
        std::cout<<arr4[i]; //writting somewhere we shouldn't...
    }
    std::cout<<'\n'<<"arr2:";
    for (int i = 0; i < sizeof(arr2)/sizeof(int); i++)
    {
        std::cout<<arr2[i]; //in fact... writting on top of arr2...
    }
    //So, arr1 should always be <= to arr2 if we want to avoid overwriting other data
}