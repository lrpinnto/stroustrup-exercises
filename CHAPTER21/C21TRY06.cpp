// CHAPTER 21 TRY 06

// First get the program as written to work and test it with a small file of a few hundred words. Then try the version that guesses about
// the size of input and see what happens when the input buffer b overflows.

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../CHAPTER20/vectoroperators.h"

int main()
{
    std::cout<<"File you want to use for input: ";
    std::string from;
    std::cin>>from;

    std::ifstream is {from};
    std::ofstream os {"C21TRY06out.txt"};

    std::istream_iterator<std::string> ii {is};
    std::istream_iterator<std::string> eos;
    std::ostream_iterator<std::string> oo {os, "\n"};
    /*
    std::vector<std::string> b {ii,eos};
    std::sort(b.begin(),b.end());
    std::copy(b.begin(),b.end(),oo);*/

    constexpr int max_size {10};
    std::vector<std::string> c {max_size};
    //int* h {new int {0}}; Causes a segmentation fault
    std::copy(ii,eos,c.begin());
    std::cout<<c<<'\n'/*<<*h*/;
}//When checking the memory using the debugger it's clear that it's overflowing, however nothing else really happens unless a new variable is
    //declared in front of the vector. In which case it seg faults.