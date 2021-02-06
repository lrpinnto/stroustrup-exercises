#include "/home/pinto/stroustrup/std_lib_facilities.h"

//CAP 4 EX 3
double sum_of_distances(vector<double>distance)
{
    double sum=0;
    for (double i : distance)
    {
        sum+=i;
    }
    return sum;
}

void teste_codigo_do_homem ()  //a puta do exercicio nao faz sentido nenhum e a resolução ainda menos
{
    vector<double> dist;

	double sum = 0;	// accumulate total distance in sum
	double min = 0;	// smallest distance
	double max = 0; // latgest distance

	cout<< "please enter a whitespace-separated sequence of doubles (representing distances) : ";
	double val = 0;
	while (cin>>val) {	// read distance
		if (val<=0) {
			//if (dist.size() == 0) error("no distances");
			cout << "total distance " << sum << '\n';
			cout << " smallest distance " << min << '\n';
			cout << "greatest distance " << max << '\n';
			cout << "mean distance " << sum/dist.size() << '\n';
			//return 0;	// exit
		}
		dist.push_back(val);	// store the value

		// update the "running" values:
		sum += val;
		if (val<min) min = val;
		if (max<val) max = val;
	}
	//if (dist.size() == 0) error("no distances");
	cout << "total distance " << sum << '\n';
	cout << " smallest distance " << min << '\n';
	cout << "greatest distance " << max << '\n';
	cout << "mean distance " << sum/dist.size() << '\n';
}

int main()
{
    
    vector<double>distance;
    for (double dist ; cin>>dist;)
    {
        distance.push_back(dist);
    }
    sort(distance);
    cout<<"\nSoma das distancias:"<<sum_of_distances(distance)<<" Media das distancias:"<<sum_of_distances(distance)/distance.size()<<" distancia minima/max:"<<distance[0]<<" "<<distance[distance.size()-1]<<"\n";
    
    //teste_codigo_do_homem();  Só o codigo mais nojento alguma vez escrito. O meu faz o mesmo por menos
}
