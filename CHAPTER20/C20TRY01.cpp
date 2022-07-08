//CHAPTER 20 TRY 01

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<double>* get_from_jill()
{
    return new vector<double> {1.0,2.31,2,2.32,-1,0};
}

int main()
{
    vector<double>* jills_data {get_from_jill()};

    cout<<*max_element(jills_data->begin(),jills_data->end())<<" address:"<<&(*max_element(jills_data->begin(),jills_data->end()))<<'\n';

    delete jills_data;
}