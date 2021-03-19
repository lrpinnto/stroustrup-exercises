#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 16

//this code doesn't work correctly

char unit_conversion(string a) //converte unidades
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
    int actual_mode_value = 0;
    int amount_of_repetitions = 0;
    double a = 0;
    int mode = 0;
    double mode_number = 0;
    double smallest = 0;
    double largest = 0;
    bool first_pass = true;
    string unit = " ";
    double sum = 0;
    vector<double>mode_numbers;
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

    for (int i = 0; i < all_numbers.size(); i++)  //check for repeating values and add them to a vector. Also adds how many times its repeating in the same vector.
    {
        if (i+1<all_numbers.size())
        {   
            if (all_numbers[i]==all_numbers[i+1] )
            {
                mode++;
                mode_number=all_numbers[i];
            }
            
            else
            {
                mode_numbers.push_back(mode_number);
                mode_numbers.push_back(mode);
                mode=0;
            }

            if (all_numbers.size()==i+2)
            {
                mode_numbers.push_back(mode_number);
                mode_numbers.push_back(mode);
            }
            
        }
    }

    for ( int i : mode_numbers) cout<<"aaa" <<i<<"aaa";
    
    for (int i = 0; i < mode_numbers.size(); i++)
    {
        if (i%2==0 && i<=mode_numbers.size()-3)
        {
            if (mode_numbers[i+1]>mode_numbers[i+3] && mode_numbers[i+1]>=actual_mode_value)
            {
                actual_mode_value = mode_numbers[i];
                amount_of_repetitions=mode_numbers[i+1];
            }
            else if (mode_numbers[i+1]<mode_numbers[i+3] && mode_numbers[i+3]>=actual_mode_value)
            {
                actual_mode_value = mode_numbers[i+2];
                amount_of_repetitions=mode_numbers[i+3];
            }

            else
            {
                //add code for more than 1 mode.
            }
            
            
        }
        else if (mode_numbers.size()<=2)
        {
            cout<<"aaaaaaaaaa";
            actual_mode_value = mode_numbers[0];
            amount_of_repetitions = mode_numbers[1];
        }
                    
    }

    cout<<"The mode is "<<actual_mode_value<<" with the total of "<<amount_of_repetitions+1<<" repetitions.\n";    
}
