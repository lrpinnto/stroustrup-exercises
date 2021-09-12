#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 6
const vector<string>numbers = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int get_number()  //converts all inputs to int. returns 0 if no match
{
	const int not_a_symbol = numbers.size();
	int val = not_a_symbol;

	if (cin>>val) 
	{
		if (val>-1 and val<10)
		{
			cout<<numbers[val];
		}
		
		
		return val; //if it's not int it gets to return but the program goes on
	}
	
	
	cin.clear(); // Clears cin

	string s;
	cin>>s;

	for (int i = 0; i < numbers.size(); i++)
		if (numbers[i]==s) val=i;
	if (val == not_a_symbol) error("unexpected number string: ",s);  //In case the input doesn't match any of the ifs.

	return val;
}

int main()
{
	while (true)
	{
		cout<<get_number()<<"\n";
	}
	
}