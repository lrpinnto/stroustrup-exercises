#include "../stroustrup/std_lib_facilities.h"

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

void teste_codigo()  //exercise doesn't make much sense
{
    vector<double> dist;

	double sum = 0;	// accumulate total distance in sum
	double min = 0;	// smallest distance
	double max = 0; // largest distance

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
    cout<<"\nSum of distances:"<<sum_of_distances(distance)<<" Mean of distances:"<<sum_of_distances(distance)/distance.size()<<" distance min/max:"<<distance[0]<<" "<<distance[distance.size()-1]<<"\n";
    
    //teste_codigo();  My code does the same thing for less
}