//CHAPTER 20 TRY 07 & 08

#include <vector>
#include <list>
#include <string.h>
#include <iostream>
#include <stdexcept>

using namespace std;

//I believe only arrays can be defined at compile time therefore we cannot use type check is_same() to check types using templates. must define a function for each case
/*template<typename T>
bool compare(const T& a)
{
    if (std::is_same<T, char[sizeof(a)/sizeof(char)]>::value)  //check type of argument
    {
        return a=="Hello";
    }
    if (std::is_same<T, vector<char>>::value)
    {
        return false;
    }
    if (std::is_same<T, list<char>>::value)
    {
        return false;
    }
    if (std::is_same<T, string>::value)
    {
        return a=="Hello";
    }
    else
    {
        throw std::invalid_argument( "Failed to identify type" );
    }
}*/

bool compare_array(const char* c, int size) //explicit conversion to pointer. otherwise, it would be implicit
{
    cout<<"Number of characters of array "<<size<<" or "<<strlen(c)<<'\n';
    if(c>"Howdy") cout<<"Howdy"; //Should comparison be done some other way?
    else if (c<"Howdy") cout<<"Hello";
    cout<<" would come first for array.\n";
    return c=="Hello";
}


int main()
{
    constexpr char a[] {"Hello"};
    const vector<char> b {'H','e','l','l','o'};
    const list<char> c {'H','e','l','l','o'};
    const string d {"Hello"};

    cout<<compare_array(a,sizeof(a)/sizeof(char));
}