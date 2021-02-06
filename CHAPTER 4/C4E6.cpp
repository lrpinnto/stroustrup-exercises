#include "/home/pinto/stroustrup/std_lib_facilities.h"

//CAP 4 EX 6
const vector<string>numbers = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int get_number()  //converte todos os inputs para int. Devolve 0 se nao bater certo.
{
	const int not_a_symbol = numbers.size();
	int val = not_a_symbol;

	if (cin>>val) 
	{
		if (val>-1 and val<10)
		{
			cout<<numbers[val];
		}
		
		
		return val; //se nao for int o return cai e o programa continua.
	}
	
	
	cin.clear(); // Só deus nosso senhor sabe, limpa o cin.

	string s;
	cin>>s;

	for (int i = 0; i < numbers.size(); i++)
		if (numbers[i]==s) val=i;
	if (val == not_a_symbol) error("unexpected number string: ",s);  //Caso se verifique, o input nao correspondeu a nenhum dos ifs vai se la saber porque. é um fall over 

	return val;
}

int main()
{
	while (true)
	{
		cout<<get_number()<<"\n";
	}
	
}