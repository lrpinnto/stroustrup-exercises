#include "../stroustrup/std_lib_facilities.h"

//Exercicio 2 capitulo 4

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
        cout<<"par";
        cout<<"Median temperature: "<<(temps[temps.size()/2]+temps[(temps.size()/2)-1])/2.0<<"\n";
        cout<<temps[temps.size()/2]<<temps[(temps.size()/2)-1];
    }
    else
    {
        cout<<"impar";
        cout<<"Median temperature: "<<temps[temps.size()/2]<<"\n";
    }
    
    
}