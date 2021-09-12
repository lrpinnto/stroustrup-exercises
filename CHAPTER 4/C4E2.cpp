#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 4 EX 2

int main()
{
    vector<double>temps;
    for (double temp; cin>>temp; )
    {
        temps.push_back(temp);
    }
    
    //median
    sort(temps);
    
    if (temps.size()%2==0)
    {
        cout<<"even\t";
        cout<<"Median temperature: "<<(temps[temps.size()/2]+temps[(temps.size()/2)-1])/2.0<<"\n";
        cout<<temps[temps.size()/2]<<temps[(temps.size()/2)-1];
    }
    else
    {
        cout<<"odd\t";
        cout<<"Median temperature: "<<temps[temps.size()/2]<<"\n";
    }
    
    
}