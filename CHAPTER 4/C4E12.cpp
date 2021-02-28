#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 12

vector<int>primes;
/* calculates prime numbers from 2 to value_max and adds them to primes */
void check_if_prime(int value_max)
{
    vector<int>get_primes;
    for (int i = 2; i <= value_max; i++)
    {
        for (int h = 2; h <= i; h++)
        {
            if (i%h==0)
            {
                if (i==h) get_primes.push_back(i);
                else break;
            }
        }
        
    }

    primes=get_primes;

}

int main()
{
    while (true)
    {
        int max_value=0;
        cout<<"Enter the max value to calculate prime numbers: ";
        cin>>max_value;
        cout<<"\n";
        check_if_prime(max_value);
        for (int i : primes)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
        primes={};
    }
}