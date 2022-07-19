//CHAPTER 20 EX 02

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdexcept>
using namespace std;

vector<double>* get_from_jill()
{
    vector<double>* p {new vector<double> {vector<double>(30)}};
    for(int i =0; i< (*p).size(); ++i)
    {
        (*p)[i] =(std::rand()%99)+double((std::rand()%10)/10.0);
    }
    return p;
}

double* get_from_jack(int* count)
{
    double* p {new double[*count]};
    for(int i =0; i<*count; ++i)
    {
        p[i]=(std::rand()%99)+double((std::rand()%10)/10.0);
    }
    return p;
}

double* high(double* first, double* last)
//return a pointer to the element in [first,last) that has the highest value
{
    double h = -1;
    double* high;
    for (double* p = first; p!=last ; ++p)
        if(h<*p){high=p;h=*p;}
    return high;
}

int main()
{
    srand(time(0));
    int jack_count {30};
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_data {get_from_jill()};

    vector<double>& v = *jill_data;

    double* jack_high = high(jack_data,jack_data+jack_count);

    for (int i = 0; i < jack_count; i++)
        cout<<jack_data[i]<<' ';
    
    cout<<"HIGH: "<<*jack_high<<'\n';

    double* jill_high = high(&v[0],&v[0]+v.size());

    for(double i : *jill_data)
        cout<<i<<' ';

    cout<<"HIGH: "<<*jill_high<<'\n';
    delete[] jack_data;
    delete jill_data;
}