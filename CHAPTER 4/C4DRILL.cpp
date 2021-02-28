#include "../stroustrup/std_lib_facilities.h"

char unit_conversion(string a) //converte unidades xDDDDDDDDDd
{
    if (a=="cm")
    {
        return 'c';
    }
    else if (a=="m")
    {
        return 'm';
    }

    else if (a=="in")
    {
        return 'i';
    }
    
    else if (a=="ft")
    {
        return 'f';
    }
    
    else
    {
        return ' ';
    }
    
    
}

int main()
{
    double a = 0;
    double smallest = 0;
    double largest = 0;
    bool first_pass = true;
    string unit = " ";
    double sum = 0;
    int counter = 0;
    vector<double>all_numbers;
    while (cin>>a>>unit)
    {

        switch (unit_conversion(unit)) //defaults to meters
        {
        case 'c':
            a*=0.01;
            break;

        case 'm':
            break;

        case 'i':
            a*=2.54;
            a*=0.01;
            break;
        
        case 'f':
            a*=12; //feet to inches
            a*=2.54; //inches to cm
            a*=0.01; //cm to m 
            break;
        
        default:
            cout<<"Wrong Unit!\n";
            continue;
            break;
        }
        if (a>largest || first_pass==true)
        {
            largest=a;
        }

        if (a<smallest || first_pass==true)
        {
            smallest=a;
        }

        

        cout<<smallest<<"m the smallest so far\t"<<largest<<"m the largest so far\t\n";

        sum+=a;
        counter++;
        all_numbers.push_back(a);

        first_pass=false;
        
    }

    cout<<"Sum of "<<sum<<" with a total of "<<counter<<" values!!\n";
    sort(all_numbers);

    for (double i : all_numbers)
    {
        cout<<i<<"m ; \n";
    }
    
    
}