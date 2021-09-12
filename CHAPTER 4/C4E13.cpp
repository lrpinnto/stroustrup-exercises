#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 13 & 14

//reference: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

int main()
{
    int p=2; //lowest prime
    int n_max=0;
    vector<int>primes;
    vector<int>sieves;
    cin>>n_max;
    for (int i = 0; i <= n_max; i++)  //create a list of all numbers n to n_max
    {
        if (i<2)
        {
            sieves.push_back(0);
        }

        else
        {
            sieves.push_back(i);
        }                        
    }


    for (int i = 0; i < sieves.size(); i++)  //runs through 0 to n_max. Only declares i as pivot if the condition below verifies
    {
        if (sieves[i]!=0)
        {
            cout<<"//"<<sieves[i]<<" "<<i<<"//";  //shows the pivots. Also shows that the pivot's index is equal to the value within the vector. 
            primes.push_back(i);  //if it's not 0, it's prime

            if (i * i < sieves.size() )    //Not sure why this happens, but there aren't any numbers to be verified when the number chosen as "pivot" square is bigger than n_max. which means, the algorithm is complete.
            {
                for (int j = i; j < sieves.size(); j = j + i) // goes from the pivot's value to n_max (which is equal to sieves.size() of pivot(j)).
                {
                    cout<<j<<" ";
                    sieves[j]=0;
                }   
            }   
        }   
    }

    cout<<"\n\n\n";
    for (int i : primes) cout<<i<<" ";
    
}