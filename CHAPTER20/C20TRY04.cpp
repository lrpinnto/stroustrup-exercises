//CHAPTER 20 TRY 04

//Find the serious error
//Potential memory leak from get_from_jack() and get_from_jill() whenever we leave fct()
//My advice would be to use smart pointers like unique_ptr for a small overhead and destruction guarantee 
//Also, jack_count is set to 0 which will generate a 0 element array. When dereferenced, the result will be undefined.

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <memory>
using namespace std;

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
    Iterator high {first};
    for (Iterator p = first; p!=last; ++p)
        if (*high<*p) high=p;
    return high;
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

vector<double>* get_from_jill()
{
    vector<double>* p {new vector<double> {vector<double>(std::rand()%10)}};
    for(int i =0; i< (*p).size(); ++i)
    {
        (*p)[i] =(std::rand()%10)+double((std::rand()%10)/10.0);
    }
    return p;
}

void fct()
{
    srand(time(0));
    int jack_count {/*0*/ 6};
    /*double* jack_data {get_from_jack(&jack_count)};    MEMORY LEAK
    vector<double>* jill_data {get_from_jill()};*/
    unique_ptr<double> jack_data {get_from_jack(&jack_count)};
    unique_ptr<vector<double>> jill_data {get_from_jill()};

    double* jack_high {high(jack_data.get(), jack_data.get()+jack_count)};  //gets the pointer without releasing 
    vector<double>& v {*jill_data};                                         //and allows for pointer arithmetics which unique_ptr does not support
    double* jill_high {high(&v[0],&v[0]+v.size())};

    cout<<"jack_data:"<<endl;
    for (size_t i = 0; i < jack_count; i++)
        cout<<(jack_data.get())[i]<<' ';
    cout<<'\n';

    cout<<"jill_data:"<<endl;
    for (auto i : *(jill_data.get()))
        cout<<i<<' ';
    cout<<'\n';

    cout<<*jack_high<<" "<<*jill_high;
}

int main()
{
    fct();
}