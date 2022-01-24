//Chapter 19 EX 03

#include <vector>
#include <iostream>
#include <string>
using namespace std;

template<typename T, typename R>
class Pair
{
private:
    T val1;
    R val2;
public:
    Pair(T def1 = T(),R def2 = R())  //use construct defaults unless the user specifies otherwise
        : val1{def1}, val2{def2}{}
    T first() const {return val1;}
    R second() const {return val2;}
    void set_first(T val){val1=val;}
    void set_second(R val){val2=val;}
};

class Symbol_table
{
private:
	vector<Pair<string,double>>var_table;  
public:
	double get_value(string s);
	void set_value(string s, double d);
	bool is_declared(string s);
	void define_var();
	void declare_var(string s, double d);
};

void Symbol_table::declare_var(string s, double d) 
{
	var_table.push_back(Pair<string,double>(s, d));
}

double Symbol_table::get_value(string s)   //gets value from calculator variable
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].first() == s) return var_table[i].second();
	throw runtime_error("get: undefined name ");   //Value not yet defined (in the calculator)
}

void Symbol_table::set_value(string s, double d)    //Assigns value to variable in the calculator
{
	for (int i = 0; i <= var_table.size(); ++i)     //goes through the vector checking for the matching name that has been pushed back beforehand
		if (var_table[i].first() == s) {
			var_table[i].set_second(d); //sets the token to the value
			return;
		}
	throw runtime_error("set: undefined name ");
}

bool Symbol_table::is_declared(string s)   //check if name is already declared
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].first() == s) return true;
	return false;
}

void Symbol_table::define_var()  //list of variables to be defined at the start of the program
{
	var_table.push_back(Pair<string,double>("pi", 3.14159));
	var_table.push_back(Pair<string,double>("e", 2.718281828));
	var_table.push_back(Pair<string,double>("k", 1000));
}

int main()
try {
    Pair<int,double> abc;
    cout<<abc.first()<<abc.second();
    Symbol_table sym;
    sym.define_var();
    sym.declare_var("test",0);
    cout<<sym.is_declared("pi")<<sym.get_value("e")<<sym.get_value("test");
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}