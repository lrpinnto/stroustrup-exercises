#include "../stroustrup/std_lib_facilities.h"

//CHAP 10 EX 02

struct Reading
{
    int hour;
    double temperature; 
    char scale;
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

void conv_c2f(vector<Reading>& v)
{
    for (int i = 0 ; i < v.size(); i++)
    {
        if (v[i].scale=='c') {v[i].temperature=(v[i].temperature*9)/5+32; v[i].scale='f';}
    }
}

istream& operator>>(istream& is, Reading& r)
{
    int hour;
    double temperature;
    char scale;
    is>>hour>>temperature>>scale;
    if(!is) return is;
    r.hour=hour;
    r.temperature=temperature;
    r.scale=scale;
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
    conv_c2f(temps);
    cout<<"Mean: "<<mean(temps)<<" Median: "<<median(temps)<<'\n';
}