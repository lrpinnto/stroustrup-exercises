//CHAPTER 20 TRY 01

//There are 2 "serious errors" according to the book
//still unsure what those might be. moving along.

#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

vector<double>* get_from_jill()
{
    vector<double>* p {new vector<double> {vector<double>(std::rand()%10)}};
    for(int i =0; i< (*p).size(); ++i)
    {
        (*p)[i] =(std::rand()%10)+double((std::rand()%10)/10.0);
    }
    return p;
}

double* get_from_jack(int* count)
{
    double* p {new double[*count]};
    for(int i =0; i<*count; ++i)
    {
        p[i]=(std::rand()%10)+double((std::rand()%10)/10.0);
    }
    return p;
}

double* high(double* first, double* last)
{
    double h=-1;
    double* high;
    for(double* p=first; p!=last; ++p)
        if(h<*p){high=p;h=*p;}
    return high;
}

int main()
{
    srand(time(0));
    int jack_count {6}; //6 or some other number
    double* jack_data=get_from_jack(&jack_count);
    
    vector<double>* jills_data {get_from_jill()};

    double* jack_high = high(jack_data, jack_data+jack_count);

    vector<double>& v = *jills_data;
    double* jill_high=high(&v[0],&v[0]+v.size());

    cout<<"Jill's max: "<<*jill_high
        <<";Jack's max: "<<*jack_high;

    delete[] jack_data;
    delete jills_data;
}