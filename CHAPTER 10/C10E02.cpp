#include "../stroustrup/std_lib_facilities.h"

//CHAP 10 EX 02

struct Reading
{
    int hour;
    double temperature; //in kelvin
};

vector<Reading> generate_randm_temps(int N, int seed)
{
    int counter {0};
    vector<Reading>values;
    Reading value;
    seed_randint(seed);
    for (int i = 0; i < N; i++)
    {
        value.temperature=(randint(1000)+randint(99)*0.01);  //arbitrary number
        value.hour = counter;
        counter++;
        if(counter>23) counter=0;
        values.push_back(value);
    }
    return values;
}

int main()
{
    const int size_of_readings {50};
    const string oname {"raw_temps.txt"};
    int seed {0};
    cout<<"Please input a number: ";
    cin>>seed;
    ofstream ost {oname};
    if(!ost) error("can't open input file ",oname);

    vector<Reading>temps {generate_randm_temps(size_of_readings,seed)};

    for (Reading r : temps)
    {
        ost<<r.hour<<" "<<r.temperature<<'\n';
    }
    
}