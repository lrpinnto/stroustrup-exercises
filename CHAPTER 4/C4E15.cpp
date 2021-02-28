#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 15

int main()
{
    int n_max=0;
    vector<int>primes;
    vector<int>sieves;
    int counter =0; //conta os numeros primos
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


    for (int i = 0; i < sieves.size(); i++)  //corre os numeros de 0 a n_max. So declara i como pivot se o acontecimento abaixo se verificar.
    {
        if (sieves[i]!=0)
        {
            if (counter>=n_max)
            {
                break; //O break quebra o ciclo mas corre o resto do codigo ate chegar ao fim.
            }
            else
            {
                counter++;
            }
            //cout<<"//"<<sieves[i]<<" "<<i<<"//";  //mostra os pivots. Demonstra tambem que o index do pivot é igual ao valor no vector.
            primes.push_back(i);  //se nao for 0, é primo.
            if (i * i < sieves.size() )    //Não sei porque isto acontece, mas já nao existem numeros para verificar quando o numero escolhido como "pivot" ao quadrado ultrapassa o n_max. Ou seja, o algoritmo está completo.
            {
                for (int j = i; j < sieves.size(); j = j + i) //vai do valor do pivot ate ao n_max (que é igual ao sieves.size()) de pivot(j))
                {
                    sieves[j]=0;
                }   
            }   
        }   
    }

    cout<<"\n\n\n";
    for (int i : primes) cout<<i<<" ";
}