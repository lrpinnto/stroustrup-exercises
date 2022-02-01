#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 15

int main()
{
    int n_max=0;
    vector<int>primes;
    vector<int>sieves;
    int counter =0; //counts prime numbers
    cin>>n_max;
    for (int i = 0; i <= n_max*n_max; i++)  //create a list of all numbers n to n_max
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

    for (int i = 0; i < sieves.size(); i++)  //Runs through numbers from 0 to n_max. Only declares i as pivot if the condition below verifies. 
    {
        if (sieves[i]!=0)
        {
            if (counter>=n_max)
            {
                break; //"break" breaks the cycle but runs through the code until it gets to the end 
            }
            else
            {
                counter++;
            }
            //cout<<"//"<<sieves[i]<<" "<<i<<"//";  //shows pivots. Demonstrates that pivot's index is equal to the value of vector.
            primes.push_back(i);  //if it's not 0. it's prime
            if (i * i < sieves.size()) 
            {
                for (int j = i; j < sieves.size(); j = j + i) //from pivots value until n_max (which is equal to sieves.size() of pivot[j])
                {
                    sieves[j]=0;
                }   
            }   
        }   
    }

    cout<<"\n\n\n";
    for (int i : primes) cout<<i<<" ";
}