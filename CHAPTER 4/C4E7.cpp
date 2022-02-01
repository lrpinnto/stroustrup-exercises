#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 7

const vector<string>numbers = {"zero","one","two","three","four","five","six","seven","eight","nine"}; //global var?

void operation (double a , double b, char op)
{
    switch (op)
    {
    case '+':
        cout<<"The sum of "<<a<<" and "<<b<<" is "<<a+b<<".\n";
        break;
    case '-':
        cout<<"The subtraction of "<<a<<" and "<<b<<" is "<<a-b<<".\n";
        break;
    case '/':
        cout<<"The division of "<<a<<" and "<<b<<" is "<<a/b<<".\n";
        break;
    case '*':
        cout<<"The product of "<<a<<" and "<<b<<" is "<<a*b<<".\n";
        break;
    
    default:
        cout<<"Please input a valid operation!";
        break;
    }
}

int get_number()  //converts all inputs to int. return 0 if no match
{
	const int not_a_symbol = numbers.size();
	int val = not_a_symbol;

	if (cin>>val) 
	{
		if (val>-1 and val<10)
		{
			cout<<numbers[val];
		}
		return val; //if it's not an int it return. but the program goes on
	}
	
	cin.clear(); // Clears cin.

	string s;
	cin>>s;

	for (int i = 0; i < numbers.size(); i++)
		if (numbers[i]==s) val=i;
	if (val == not_a_symbol) error("unexpected number string: ",s);  //In case the input doesn't match any of the ifs. fall over

	return val;
}

int main ()
{
    double a = 0;
    double b = 0;
    char op = 0;
    while (true)
    {
        cout<<"Please enter the desired operation:\n\t";
        a=get_number();
        cin>>op;
        b=get_number();
        operation(a,b,op);
    }
}