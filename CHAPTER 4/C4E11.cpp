#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 11

const vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

/* Generates a vector composed of all prime numbers from 0 to 100, compares that to reference, and checks if the provided int value is in this vector (is a prime number */
bool check_if_prime(int number)
{
    bool is_prime=false;
    vector<int>get_primes;
    for (int i = 2; i <= 100; i++)
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

    if (get_primes.size()==primes.size())  // compares the generated vector with the references to verify if the input is prime
    {
        for (int i = 0; i < get_primes.size(); i++)
        {
            if (get_primes[i]!=primes[i])
            {
                cout<<"vectors don't match";
                break;
            }
            if (number==get_primes[i])
            {
                is_prime=true;
            }
            
        }
    }

    else cout<<"vectors don't match";
    
    if (is_prime==true) return true;
    else return false;
}

int main()
{
    for (int i = 0; i < 101; i++)
    {
        if (check_if_prime(i)==true)
        {
            cout<<" prime ";
        }
        else cout<<i;
        
    }
           
}