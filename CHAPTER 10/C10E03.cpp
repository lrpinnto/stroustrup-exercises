#include "../stroustrup/std_lib_facilities.h"

//CHAP 10 EX 02

struct Reading
{
    int hour;
    double temperature; //in kelvin
};

double mean(const vector<Reading>& v)
{
    const int size_v {v.size()};
    double sum {0};
    for (Reading r : v)
    {
        sum+=r.temperature;
    }
    return sum/size_v;
}

double median(const vector<Reading>& v)
{
    const int size_v {v.size()};
    if (size_v%2==0)
    {
        return (v[size_v/2].temperature+v[(size_v/2)-1].temperature)/2;
    }
    else return v[ceil(size_v/2)].temperature;
    
}

istream& operator>>(istream& is, Reading& r)
{
    int hour;
    double temperature;
    is>>hour>>temperature;
    if(!is) return is;
    r.hour=hour;
    r.temperature=temperature;
    return is;
}

int main()
{
    const string iname {"raw_temps.txt"};
    vector<Reading>temps;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);
    while(true){
        Reading r;
        if(!(ifs>>r)) break;
        temps.push_back(r);
    }
    cout<<"Mean: "<<mean(temps)<<" Median: "<<median(temps)<<'\n';
}